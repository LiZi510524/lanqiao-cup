#ifndef __ICC_H__
#define __ICC_H__

#include <STC15F2K60S2.H>

static void I2C_Delay(unsigned char n);
unsigned char I2CReceiveByte(void);
unsigned char I2CWaitAck(void);
void I2CSendByte(unsigned char byt);
void I2CSendAck(unsigned char ackbit);
void I2CStart(void);
void I2CStop(void);

void write_byte_at24c02(unsigned char addr,unsigned char dat);
unsigned char read_byte_at24c02(unsigned char addr);

#endif