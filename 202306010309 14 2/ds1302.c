/*	# 	DS1302代码片段说明
	1. 	本文件夹中提供的驱动代码供参赛选手完成程序设计参考。
	2. 	参赛选手可以自行编写相关代码或以该代码为基础，根据所选单片机类型、运行速度和试题
		中对单片机时钟频率的要求，进行代码调试和修改。
*/								
#include "hardware.h"

sbit SCK=P1^7;
sbit SDA=P2^3;
sbit RST=P1^3;

//
void Write_Ds1302(unsigned  char temp) 
{
	unsigned char i;
	for (i=0;i<8;i++)     	
	{ 
		SCK = 0;
		SDA = temp&0x01;
		temp>>=1; 
		SCK=1;
	}
}   

//
void Write_Ds1302_Byte( unsigned char address,unsigned char dat )     
{
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
 	RST=1; 	_nop_();  
 	Write_Ds1302(address);	
 	Write_Ds1302(dat);		
 	RST=0; 
}

//
unsigned char Read_Ds1302_Byte ( unsigned char address )
{
 	unsigned char i,temp=0x00;
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
 	RST=1;	_nop_();
 	Write_Ds1302(address);
 	for (i=0;i<8;i++) 	
 	{		
		SCK=0;
		temp>>=1;	
 		if(SDA)
 		temp|=0x80;	
 		SCK=1;
	} 
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
	SCK=1;	_nop_();
	SDA=0;	_nop_();
	SDA=1;	_nop_();
	return (temp);			
}

void write_ds1302()
{
	digs=display[0];
	Write_Ds1302_Byte(0x84,digs[0]*0x10+digs[1]);
	Write_Ds1302_Byte(0x82,digs[3]*0x10+digs[4]);
	Write_Ds1302_Byte(0x80,digs[6]*0x10+digs[7]);
}

void read_ds1302()
{
	//u8 temp;
	digs=display[0];
	
//	temp=Read_Ds1302_Byte(0x85);
//	digs[0]=temp/0x10;
//	digs[1]=temp%0x10;
//	
//	temp=Read_Ds1302_Byte(0x83);
//	digs[3]=temp/0x10;
//	digs[4]=temp%0x10;
//	
//	temp=Read_Ds1302_Byte(0x81);
//	digs[6]=temp/0x10;
//	digs[7]=temp%0x10;
	
	digs[0]=Read_Ds1302_Byte(0x85)/0x10;
	digs[1]=Read_Ds1302_Byte(0x85)%0x10;
	
	digs[3]=Read_Ds1302_Byte(0x83)/0x10;
	digs[4]=Read_Ds1302_Byte(0x83)%0x10;
	
	digs[6]=Read_Ds1302_Byte(0x81)/0x10;
	digs[7]=Read_Ds1302_Byte(0x81)%0x10;
}
