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

    unsigned char EEPROM_Read(unsigned int add);
    void EEPROM_Write(unsigned int add, unsigned char data);

#ifdef	__cplusplus
}
#endif

#endif	/* 24LC256_H */

