#include "DS32321.h"
#include "config.h"

void I2C_Start_DS(void)
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
  SEN = 1;  // initiate start condition
}
 
void I2C_Repeated_Start_DS(void)
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
  RSEN = 1;  // initiate repeated start condition
}
 
void I2C_Stop_DS(void)
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
  PEN = 1;  // initiate stop condition
}
 
void I2C_Write_DS(unsigned char i2c_data)
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
  SSPBUF = i2c_data;  // update buffer
}
 
unsigned char I2C_Read_DS(unsigned char ack)
{
  unsigned char data;
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
  RCEN = 1;
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
  data = SSPBUF;  // read data from buffer
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
  // send acknowledge pulse ? (depends on ack, if 1 send, otherwise don't send)
  ACKDT = !ack;
  ACKEN = 1;
  return data;  // return data read
}
