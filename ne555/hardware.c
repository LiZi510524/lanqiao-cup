#include <STC15F2K60S2.H>
#include "hardware.h"


/*************  本地常量声明    **************/
u8 code t_display[]={                       //标准字库
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
//black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
    0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
    0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46};    //0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1

u8 code T_COM[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};      //位码

u8 display[][8]=
{
	{10,16,16,16,16,16,16,16}//测距界面
};

u8 *digs=display;
u8 led=0xff;
u8 n=0;

void close()
{
	P2=0X00;
	
	P0=0X00;
	P2|=0XA0;
	P2&=0X1F;
	
	P0=0XFF;
	P2|=0X80;
	P2&=0X1F;
}

void seg_dis()
{
	P0=0X00;
	P2|=0XC0;
	P2&=0X1F;
	
	P0=~t_display[digs[n]];
	P2|=0XE0;
	P2&=0X1F;
	
	P0=T_COM[n];
	P2|=0XC0;
	P2&=0X1F;
	
	if(++n>7)
		n=0;
}