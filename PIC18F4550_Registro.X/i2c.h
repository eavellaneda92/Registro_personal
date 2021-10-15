/* 
 * File:   i2c.h
 * Author: EAVELLANEDA
 *
 * Created on 23 de enero de 2021, 11:34 PM
 */

// I2C Speed Control Macros
#define I2C_STANDARD_SPEED        0u
#define I2C_HIGH_SPEED            1u

/*Public Function Declaration*/
void I2C_Init( unsigned char speed );
void I2C_Start( void );
void I2C_Restart( void );
void I2C_Stop( void );
void I2C_Wait( void );
void I2C_Send( unsigned char data );
unsigned char I2C_Read ( void );


