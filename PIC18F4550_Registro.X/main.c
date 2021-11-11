/*
 * File:   main.c
 * Author: EAVELLANEDA
 *
 * Created on 14 de octubre de 2021, 22:38
 */

#include "config.h"
#include "Oled.h"
#include "stdio.h"
#include "DS32321.h"
#include "UART.h"
#include "Timer1.h"
#include "RC522.h"
char UID[10]; 
char sms[10];
char *TagType; 
#include "24lc256.h"

//VARIABLES Y FUNCIONES PARA USO DE MEMORIA EEPROM


//ESTRUCTURA DE VARIABLES PARA PANTALLA Y RTC
#define SET     PORTEbits.RE0
#define UP      PORTEbits.RE1
#define DOWN    PORTEbits.RE2
#define BUZZER  LATDbits.LATD6
void get_key(void);
char configuracion = 0;
unsigned char Horax = 0;
unsigned char Minutox = 0;
unsigned char Segundox = 0;
unsigned char Hora = 22;
unsigned char Minuto = 49;
unsigned char Segundo = 1;
unsigned char anio = 21;
unsigned char mes = 10;
unsigned char dia = 28;
unsigned char aniox = 21;
unsigned char mesx = 10;
unsigned char diax = 28;

//FUNCIONES PARA IMPRESORA Y RC622
void Print_Ticket(unsigned int valor);
void CHECK_TAG(void);
void New_Line(void);
void Font_Big(void);
void Font_Normal(void);

//FUNCIONES PARA PANTALLA
void Print_Menu(void);
void Print_Hora(void);
void Print_Minuto(void);
void Print_Segundo(void);
void Print_Dia(void);
void Print_Mes(void);
void Print_Anio(void);
void Print_config(void);

//FUNCIONES Y VARIABLES PARA fu RTC
void set_RTC(void);
void get_RTC(void);
unsigned char bcd_to_decimal(unsigned char number);
unsigned char decimal_to_bcd(unsigned char number);
unsigned int contador_t1 = 0;
char flag_t1 = 0;

//VARIABLES PARA MEMORIA
unsigned int registro = 0;

void __interrupt() scr(){
    if(PIR1bits.TMR1IF){
        contador_t1++;
        if(contador_t1>=2){ //aprox 40ms 
            flag_t1 = 1;
            contador_t1 = 0;
        }
        TMR1 = 5553;
        PIR1bits.TMR1IF = 0;
    }
}

void main(void) {
    //OSCCONbits.IRCF = 0b111;
    //ANALOGICO/DIGITAL
    ADCON1 = 0x0F;
    TRISE = 0xF;
    TRISDbits.RD6 = 0;
    BUZZER = 0;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    //TIMER 1
    Timer1_Init();
    
    //PUERTO SERIE
    UART_Init();
    UART_Begin(9600);
    UART_Println("Inicio");
    //PANTALLA OLED
    __delay_ms(1500);
    OLED_Init();
    Print_Menu();
    
    //PUERTO NFC
    MFRC522_Init();
    
    //Si la memoria esta es nueva la prepara para inicio
    if(EEPROM_Read(1) != 22){
        EEPROM_setRegistro(0);
        EEPROM_Write(1,22);
    }else{
        registro = EEPROM_getRegistro();
    }
    
    while(1){
        get_key();
        if(configuracion == 0){
            //Espera de tiempo para leer tiempo
            if(flag_t1){
                get_RTC(); //En esta funcion tambien se imprime el reloj
                flag_t1 = 0;
            }
            //Lectura de TARJETA
            CHECK_TAG();
        }
    }
}

//Funciones OLED
void Print_Menu(void){
    OLEDClear();
    OLED_SPuts(0,0,"LECOMPERU");
    OLEDsetCursor(0,2);
    OLED_NPuts("REGISTRO PERSONAL");
    Print_Hora();
    Print_Minuto();
    Print_Segundo();
    Print_config();
}
void Print_Hora(void){
    sprintf(sms,"%d%d:",Hora/10,Hora%10);
    OLED_SPuts(10,5,sms);
}
void Print_Minuto(void){
    sprintf(sms,"%d%d:",Minuto/10,Minuto%10);
    OLED_SPuts(50,5,sms);
}
void Print_Segundo(void){
    sprintf(sms,"%d%d",Segundo/10,Segundo%10);
    OLED_SPuts(90,5,sms);
}
void Print_Dia(void){
    sprintf(sms,"%d%d",dia/10,dia%10);
    OLED_SPuts(90,6,sms);
}
void Print_Mes(void){
    sprintf(sms,"%d%d-",mes/10,mes%10);
    OLED_SPuts(50,6,sms);
}
void Print_Anio(void){
    sprintf(sms,"%d%d-",anio/10,anio%10);
    OLED_SPuts(10,6,sms);
}
void Print_config(void){
    if(configuracion == 0)  OLED_SPuts(50,7,"    ");
    if(configuracion == 1)  OLED_SPuts(50,7,"MIN");
    if(configuracion == 2)  OLED_SPuts(50,7,"HORA");
    if(configuracion == 3)  OLED_SPuts(50,7,"DIA");
    if(configuracion == 4)  OLED_SPuts(50,7,"MES");
    if(configuracion == 5)  OLED_SPuts(50,7,"YEAR");
}

//Funciones RTC
unsigned char bcd_to_decimal(unsigned char number) {
  return((number >> 4) * 10 + (number & 0x0F));
}
unsigned char decimal_to_bcd(unsigned char number) {
  return((unsigned char)(((number / 10) << 4) + (number % 10)));
}
void get_RTC(void){
    I2C_Start_DS();           
    I2C_Write_DS(0xD0);       
    I2C_Write_DS(0);          
    I2C_Repeated_Start_DS();  
    I2C_Write_DS(0xD1);       
    Segundo = I2C_Read_DS(1);  
    Minuto = I2C_Read_DS(1);  
    Hora = I2C_Read_DS(1);
    if(Hora != Horax){
        Horax = Hora;
        Print_Hora();
    }
    if(Minuto != Minutox){
        Minutox = Minuto;
        Print_Minuto();
    }
    if(Segundo != Segundox){
        Segundox = Segundo;
        Print_Segundo();
    }
    I2C_Read_DS(1);           
    dia = I2C_Read_DS(1);
    mes = I2C_Read_DS(1);  
    anio = I2C_Read_DS(0);
    if(dia != diax){
        Print_Dia();
        diax = dia;
    }
    if(mes != mesx){
        mesx = mes;
        Print_Mes();
    }
    if(anio != aniox){
        aniox = anio;
        Print_Anio();
    }
    I2C_Stop_DS();            
}
void set_RTC(void){
      Hora = decimal_to_bcd(Hora);
      Minuto = decimal_to_bcd(Minuto);
      Segundo = decimal_to_bcd(Segundo);
      anio = decimal_to_bcd(anio);
      mes = decimal_to_bcd(mes);
      dia = decimal_to_bcd(dia);
 
      // Write data to DS3231 RTC
      I2C_Start_DS();         
      I2C_Write_DS(0xD0);    
      I2C_Write_DS(0);        
      I2C_Write_DS(Segundo);        
      I2C_Write_DS(Minuto);   
      I2C_Write_DS(Hora);     
      I2C_Write_DS(1);        
      I2C_Write_DS(dia);    
      I2C_Write_DS(mes);    
      I2C_Write_DS(anio);    
      I2C_Stop_DS();   
      __delay_ms(6);
}
void get_key(void){
    if(!SET){
        if(!SET){
            configuracion++;
            if(configuracion >= 6){
                set_RTC();
                configuracion = 0;
            }    
            Print_config();
            BUZZER = 1;
            __delay_ms(300);
            BUZZER = 0;
            __delay_ms(300);
            while(!SET);
        }
    }
    if(!UP){
        if(configuracion == 1){
            Minuto++;
            if(Minuto>=60) Minuto = 0;
            Print_Minuto();
        }
        if(configuracion == 2){
            Hora++;
            if(Hora>=24) Hora = 0;
            Print_Hora();
        }
        if(configuracion == 3){
            dia++;
            if(dia>=31) dia = 1;
            Print_Dia();
        }
        if(configuracion == 4){
            mes++;
            if(mes>=13) mes = 1;
            Print_Mes();
        }
        if(configuracion == 5){
            anio++;
            if(anio>=99) anio = 0;
            Print_Anio();
        }
        __delay_ms(200);
        while(!UP);
    }
    if(!DOWN){
        if(configuracion == 1){
            if(Minuto == 0) Minuto = 60;
            Minuto--;
            Print_Minuto();
        }
        if(configuracion == 2){
            if(Hora == 0) Hora = 24;
            Hora--;
            Print_Hora();
        }
        if(configuracion == 3){
            if(dia == 1) dia = 32;
            dia--;
            Print_Dia();
        }
        if(configuracion == 4){
            if(mes == 1) mes = 13;
            mes--;
            Print_Mes();
        }
        if(configuracion == 5){
            if(anio == 0) anio = 100;
            anio--;
            Print_Anio();
        }
        __delay_ms(200);
        while(!DOWN);
    }
}

//Funcion Impresora
void Print_Ticket(unsigned int valor){
    Valores[0] = bcd_to_decimal(Valores[0]);
    Valores[1] = bcd_to_decimal(Valores[1]);
    Valores[2] = bcd_to_decimal(Valores[2]);
    New_Line();
    sprintf(sms,"%d%d:",Hora/10,Hora%10);
    UART_Print(sms);
    sprintf(sms,"%d%d:",Minuto/10,Minuto%10);
    UART_Print(sms);
    sprintf(sms,"%d%d",Segundo/10,Segundo%10);
    UART_Println(sms);
    New_Line();
    Font_Big();
    UART_Print("ID: ");
    sprintf(sms,"%d",valor);
    UART_Println(sms);
    Font_Normal();
    UART_Println("Recuerde conservar su ticket");
    New_Line();
    New_Line();
    New_Line();
    UART_Write(0x1B);UART_Write(0x6D);
}

//Funcion RFID
void CHECK_TAG(void){
   if(MFRC522_isCard(TagType)){              // Verificacion si hay un tag disponible
      if(MFRC522_ReadCardSerial(UID)){       // Lectura y verificacion si encontro algun tag
         int i = 0;
         for(i=0; i<5; i++){                  // Imprime la ID en la pantalla LCD
            Aux[i] = UID[i];
         }       
         unsigned int valor = Registro_busqueda();
         if(valor == 0){
            Valores[0] = Hora;
            Valores[1] = Minuto;
            Valores[2] = dia;
            Valores[3] = mes;
            Valores[4] = anio;
            Guarda_ID();
            valor = EEPROM_getRegistro();
         }else{
            Muestra_ID(valor);
         }
         Print_Ticket(valor);
         MFRC522_Clear_UID(UID);             // Limpia temporalmente la ID
      }
      MFRC522_Halt();                        // Apaga la antena
   }
}


void New_Line(void){
    UART_Write(0x0d);
    UART_Write(0x0a);
}

void Font_Big(void){
    UART_Write(0x1b);
    UART_Write(0x40);
    UART_Write(0x1d);
    UART_Write(0x21);
    UART_Write(0x10);
    UART_Write(0x08);
}

void Font_Normal(void){
    UART_Write(0x1b); 
    UART_Write(0x40); 
    UART_Write(0x1d); 
    UART_Write(0x21); 
    UART_Write(0x00);
    UART_Write(0x0d); 
    UART_Write(0x0a);
    UART_Write(0x1B); 
    UART_Write(0x44); 
    UART_Write(0x00);
    UART_Write(0x1B); 
    UART_Write(0x40); 
    UART_Write(0x1B); 
    UART_Write(0x2D); 
    UART_Write(0x00);
}