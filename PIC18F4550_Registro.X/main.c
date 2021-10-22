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
char *TagType; 

#include "24lc256.h"

//ESTRUCTURA DE VARIABLES PARA PANTALLA Y RTC
unsigned char Hora = 22;
unsigned char Minuto = 49;
unsigned char Segundo = 1;
unsigned char anio = 20;
unsigned char mes = 10;
unsigned char dia = 1;

//FUNCIONES PARA IMPRESORA Y RC622
void Print_Ticket(void);
void CHECK_TAG(void);

//FUNCIONES PARA PANTALLA
void Print_Menu(void);
void Print_Hora(void);
void Print_Minuto(void);
void Print_Segundo(void);

//FUNCIONES Y VARIABLES PARA fu RTC
void set_RTC(void);
void get_RTC(void);
unsigned char bcd_to_decimal(unsigned char number);
unsigned char decimal_to_bcd(unsigned char number);
unsigned int contador_t1 = 0;
char flag_t1 = 0;

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
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    //TIMER 1
    Timer1_Init();
    
    //PUERTO SERIE
    UART_Init();
    UART_Begin(9600);
    UART_Println("Hola mundo");
    //__delay_ms(1500);
    OLED_Init();
    set_RTC();
    if(EEPROM_Read(1) != 22){
        
    }
    UART_Write(EEPROM_Read(0x10));
    while(1){
        //Espera de tiempo para leer tiempo
        if(flag_t1){
            get_RTC();
            Print_Ticket();
            flag_t1 = 0;
        }
        //Lectura de TARJETE
        //CHECK_TAG();
    }
}

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
    char sms[10];
    sprintf(sms,"%d%d:",Hora/10,Hora%10);
    OLED_SPuts(10,5,sms);
}

void Print_Minuto(void){
    char sms[10];
    sprintf(sms,"%d%d:",Minuto/10,Minuto%10);
    OLED_SPuts(50,5,sms);
}

void Print_Segundo(void){
    char sms[10];
    sprintf(sms,"%d%d",Segundo/10,Segundo%10);
    OLED_SPuts(90,5,sms);
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
    I2C_Read_DS(1);           
    dia = I2C_Read_DS(1);  
    mes = I2C_Read_DS(1);  
    anio = I2C_Read_DS(0);  
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

void Print_Ticket(void){
    Hora = bcd_to_decimal(Hora);
    Minuto = bcd_to_decimal(Minuto);
    Segundo = bcd_to_decimal(Segundo);
    char sms[10];
    sprintf(sms,"%d%d:",Hora/10,Hora%10);
    UART_Print(sms);
    sprintf(sms,"%d%d:",Minuto/10,Minuto%10);
    UART_Print(sms);
    sprintf(sms,"%d%d",Segundo/10,Segundo%10);
    UART_Println(sms);
}

unsigned char bcd_to_decimal(unsigned char number) {
  return((number >> 4) * 10 + (number & 0x0F));
}
 
unsigned char decimal_to_bcd(unsigned char number) {
  return((unsigned char)(((number / 10) << 4) + (number % 10)));
}

void CHECK_TAG(void){
   if(MFRC522_isCard(TagType)){              // Verificacion si hay un tag disponible
      if(MFRC522_ReadCardSerial(UID)){       // Lectura y verificacion si encontro algun tag
         UART_Println("ID: ");
         int i = 0;
         char buf[20];
         for(i=0; i<5; i++){                  // Imprime la ID en la pantalla LCD
            sprintf(buf, "%d ", UID[i]);
            UART_Println(buf);
         }       
         UART_Println("PASA PROCESO 3");
         MFRC522_Clear_UID(UID);             // Limpia temporalmente la ID
      }
      MFRC522_Halt();                        // Apaga la antena
   }
}