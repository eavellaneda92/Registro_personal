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

void Guarda_ID(void){
    unsigned int registro = EEPROM_getRegistro();
    registro++;
    EEPROM_setRegistro(registro);
}

void Muestra_ID(unsigned int valor){
    Valores[0] = EEPROM_Read(valor * 10);
    Valores[1] = EEPROM_Read(valor * 10 + 1);
    Valores[2] = EEPROM_Read(valor * 10 + 2);
    Valores[3] = EEPROM_Read(valor * 10 + 3);
    Valores[4] = EEPROM_Read(valor * 10 + 4);
    Aux[0] = EEPROM_Read(valor * 10 + 5);
    Aux[1] = EEPROM_Read(valor * 10 + 6);
    Aux[2] = EEPROM_Read(valor * 10 + 7);
    Aux[3] = EEPROM_Read(valor * 10 + 8);
    Aux[4] = EEPROM_Read(valor * 10 + 9);
}

unsigned int Registro_busqueda(void){
    unsigned int registro = EEPROM_getRegistro();
    for(unsigned int i = 1; i <= registro; i++){
        unsigned char datox = EEPROM_Read(i*10 + 5);
        if(datox == Aux[0]){
            datox = EEPROM_Read(i*10 + 6);
            if(datox == Aux[1]){
                datox = EEPROM_Read(i*10 + 7);
                if(datox == Aux[2]){
                    datox = EEPROM_Read(i*10 + 8);
                    if(datox == Aux[3]){
                        datox = EEPROM_Read(i*10 + 9);
                        if(datox == Aux[4]){
                            return i;
                        }
                    }
                }
            }
        }
    }
    return 0;
}