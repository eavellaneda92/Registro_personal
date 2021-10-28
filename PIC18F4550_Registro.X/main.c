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
void Print_Ticket(void);
void CHECK_TAG(void);

//FUNCIONES PARA PANTALLA
void Print_Menu(void);
void Print_Hora(void);
void Print_Minuto(void);
void Print_Segundo(void);
void Print_Dia(void);
void Print_Mes(void);
void Print_anio(void);

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
    OSCCONbits.IRCF = 0b111;
    //ANALOGICO/DIGITAL
    ADCON1 = 0x0F;
    TRISE = 0xF;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    //TIMER 1
    Timer1_Init();
    
    //PUERTO SERIE
    UART_Init();
    UART_Begin(9600);
    UART_Println("Hola mundo");
    
    //PANTALLA OLED
    __delay_ms(1500);
    OLED_Init();
    Print_Menu();
    set_RTC();
    
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
                //Print_Ticket();
                flag_t1 = 0;
            }
            //Lectura de TARJETA
            CHECK_TAG();
        }else{
            
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
void Print_dia(void){
    sprintf(sms,"%d%d",dia/10,dia%10);
    OLED_SPuts(90,6,sms);
}
void Print_mes(void){
    sprintf(sms,"%d%d",mes/10,mes%10);
    OLED_SPuts(50,6,sms);
}
void Print_anio(void){
    sprintf(sms,"%d%d",anio/10,anio%10);
    OLED_SPuts(10,6,sms);
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
        Print_dia();
        diax = dia;
    }
    if(mes != mesx){
        mesx = mes;
        Print_mes();
    }
    if(anio != aniox){
        aniox = anio;
        Print_anio();
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
        if(configuracion == 0){
            configuracion = 1;
            BUZZER = 1;
            __delay_ms(300);
            BUZZER = 0;
            __delay_ms(300);
            while(!SET);
        }else{
            configuracion = 1;
            BUZZER = 1;
            __delay_ms(300);
            BUZZER = 0;
            __delay_ms(300);
            while(!SET);
        }
    }
    if(!UP){
        if(configuracion){
            Minuto++;
            if(Minuto>=60){
                Minuto = 0;
                Hora++;
                if(Hora>=24) Hora = 0;
            }
            __delay_ms(200);
            while(!UP);
        }
    }
}

//Funcion Impresora
void Print_Ticket(void){
    Hora = bcd_to_decimal(Hora);
    Minuto = bcd_to_decimal(Minuto);
    Segundo = bcd_to_decimal(Segundo);
    sprintf(sms,"%d%d:",Hora/10,Hora%10);
    UART_Print(sms);
    sprintf(sms,"%d%d:",Minuto/10,Minuto%10);
    UART_Print(sms);
    sprintf(sms,"%d%d",Segundo/10,Segundo%10);
    UART_Println(sms);
}

//Funcion RFID
void CHECK_TAG(void){
   if(MFRC522_isCard(TagType)){              // Verificacion si hay un tag disponible
      if(MFRC522_ReadCardSerial(UID)){       // Lectura y verificacion si encontro algun tag
         UART_Println("ID: ");
         int i = 0;
         char buf[20];
         for(i=0; i<5; i++){                  // Imprime la ID en la pantalla LCD
            Aux[i] = UID[i];
            Print_Ticket();
         }       
         Registro_busqueda(Aux);
         MFRC522_Clear_UID(UID);             // Limpia temporalmente la ID
      }
      MFRC522_Halt();                        // Apaga la antena
   }
}