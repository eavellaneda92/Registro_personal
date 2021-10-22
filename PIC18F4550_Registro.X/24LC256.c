#include "24lc256.h"
#include "i2c.h"
#include "config.h"

#define EEPROM_Address_R 0xA1
#define EEPROM_Address_W 0xA0
unsigned int add = 0xa1;

void EEPROM_Write(unsigned int add, unsigned char data)
{
  I2C_Start();
  I2C_Send(EEPROM_Address_W);
  I2C_Send((add>>8));
  I2C_Send((unsigned char)add);
  I2C_Send(data);
  I2C_Stop();
  __delay_ms(5);
}

unsigned char EEPROM_Read(unsigned int add)
{
    I2C_Start();
    I2C_Send(EEPROM_Address_W);
    I2C_Send((add>>8));
    I2C_Send((unsigned char)add);
    I2C_Restart();
    I2C_Send(EEPROM_Address_R);
    unsigned char temp;
    temp = I2C_Read();
    return temp;
}

