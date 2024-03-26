#ifndef __DS1302_H__
#define __DS1302_H__

#include <STC15F2K60S2.H>
#include "intrins.h"

void Write_Ds1302(unsigned  char temp);
void Write_Ds1302_Byte(unsigned char address,unsigned char dat );
unsigned char Read_Ds1302_Byte ( unsigned char address );

void time_write();
void time_read();

#endif
