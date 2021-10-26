#include "24lc256.h"
#include "i2c.h"
#include "config.h"

#define EEPROM_Address_R 0xA1
#define EEPROM_Address_W 0xA0
unsigned int add = 0xa1;

void EEPROM_Write(unsigned int add, unsigned char data){
  I2C_Start();
  I2C_Send(EEPROM_Address_W);
  I2C_Send((add>>8));
  I2C_Send((unsigned char)add);
  I2C_Send(data);
  I2C_Stop();
  __delay_ms(5);
}
unsigned char EEPROM_Read(unsigned int add){
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
unsigned int EEPROM_getRegistro(void){
    unsigned int registro = 0;
    registro = EEPROM_Read(2);
    registro = (registro << 8) | EEPROM_Read(3);
    return registro;
}
void EEPROM_setRegistro(unsigned int registro){
    EEPROM_Write(2,(unsigned char)(registro / 100));
    EEPROM_Write(3,(unsigned char)(registro % 100));
}
int Registro_busqueda(char aux[5]){
    unsigned int numero = EEPROM_getRegistro();
    for(int i=0; i< numero ;i++){
        
    }
    return 1;
}
