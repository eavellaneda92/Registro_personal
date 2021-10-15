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

//ESTRUCTURA DE VARIABLES PARA PANTALLA Y RTC
unsigned int Hora = 22;
unsigned int Minuto = 49;
unsigned int Segundo = 1;

//FUNCIONES PARA IMPRESORA
void Print_Ticket(void);

//FUNCIONES PARA PANTALLA
void Print_Menu(void);
void Print_Hora(void);
void Print_Minuto(void);
void Print_Segundo(void);

//FUNCIONES PARA RTC
void set_RTC(void);
void get_RTC(void);
unsigned char bcd_to_decimal(unsigned char number);
unsigned char decimal_to_bcd(unsigned char number);
unsigned int anio = 20;
unsigned int mes = 10;
unsigned int dia = 1;

void main(void) {
    OSCCONbits.IRCF = 0b111;
    //ANALOGICO/DIGITAL
    ADCON1 = 0x0F;
    
    //PUERTO SERIE
    UART_Init();
    UART_Begin(9600);
    UART_Println("Hola mundo");
    __delay_ms(1500);
    OLED_Init();
    set_RTC();
    while(1){
        get_RTC();
        Print_Ticket();
        __delay_ms(1000);
    }
}

void Print_Menu(void){
    OLEDClear();
    OLED_SPuts(0,0,"LECOM");
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
    Hora   = I2C_Read_DS(1);  
    I2C_Read_DS(1);           
    dia  = I2C_Read_DS(1);  
    mes  = I2C_Read_DS(1);  
    anio   = I2C_Read_DS(0);  
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
  return(((number / 10) << 4) + (number % 10));
}