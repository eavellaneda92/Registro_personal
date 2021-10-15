/* 
 * File:   DS32321.h
 * Author: EAVELLANEDA
 *
 * Created on 14 de octubre de 2021, 23:45
 */

#ifndef DS32321_H
#define	DS32321_H

#ifdef	__cplusplus
extern "C" {
#endif

    void I2C_Start_DS(void);
    void I2C_Repeated_Start_DS(void);
    void I2C_Stop_DS(void);
    void I2C_Write_DS(unsigned char i2c_data);
    unsigned char I2C_Read_DS(unsigned char ack);


#ifdef	__cplusplus
}
#endif

#endif	/* DS32321_H */

