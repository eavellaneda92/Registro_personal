/*
 * File:   main.c
 * Author: EAVELLANEDA
 *
 * Created on 14 de octubre de 2021, 22:38
 */


#include "config.h"
#include "Oled.h"
#include "stdio.h"

//ESTRUCTURA DE VARIABLES PARA PANTALLA
unsigned int Hora = 22;
unsigned int Minuto = 49;
unsigned int Segundo = 1;

void Print_Menu(void);
void Print_Hora(void);
void Print_Minuto(void);
void Print_Segundo(void);

void main(void) {
    OSCCONbits.IRCF = 0b111;
    //ANALOGICO/DIGITAL
    ADCON1 = 0x0F;
    __delay_ms(1500);
    Print_Menu();
    
    while(1){
        Segundo++;
        if(Segundo>=60) Segundo = 0;
        Print_Segundo();
        __delay_ms(1000);
    }
}

void Print_Menu(void){
    OLED_Init();
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