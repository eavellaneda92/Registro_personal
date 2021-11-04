/* 
 * File:   24lc256.h
 * Author: EAVELLANEDA
 *
 * Created on 22 de octubre de 2021, 16:08
 */

#ifndef M24LC256_H
#define	M24LC256_H

#ifdef	__cplusplus
extern "C" {
#endif
    char Valores[5];
    char Aux[5];
    void Guarda_ID(void);
    void Muestra_ID(unsigned int valor);
    unsigned char EEPROM_Read(unsigned int add);
    void EEPROM_Write(unsigned int add, unsigned char data);
    unsigned int EEPROM_getRegistro(void);
    void EEPROM_setRegistro(unsigned int registro);
    unsigned int Registro_busqueda(void);

#ifdef	__cplusplus
}
#endif

#endif	/* 24LC256_H */

