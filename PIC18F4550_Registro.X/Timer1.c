#include <pic18f4550.h>

#include "Timer1.h"

//Void inicio de interrupciones y temporizador
void Timer1_Init(void){
    T1CONbits.RD16 = 1;
    T1CONbits.T1RUN = 0;
    T1CONbits.T1OSCEN = 0;
    T1CONbits.TMR1CS = 0;
    TMR1 = 5553;
    T1CONbits.TMR1ON = 1;
    T1CONbits.T1CKPS = 0b11; //prescaler de 8
    PIE1bits.TMR1IE = 1;
    PIR1bits.TMR1IF = 0; 
}

