/* 
 * File:   UART.h
 * Author: EAVELLANEDA
 *
 * Created on 15 de octubre de 2021, 0:11
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    unsigned long valores[10];
    void UART_Init(void);
    void UART_Begin(unsigned long baud);
    void UART_Write( char data);
    void UART_Println(char *buffer);
    void UART_Print(char *buffer); 


#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

