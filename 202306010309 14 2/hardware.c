#include "hardware.h"

void Timer0_Init();
void Timer1_Init();
void Timer1_isr();

/*************  ??????    **************/
u8 code t_display[]={                       //????
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
//black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
    0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
    0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46};    //0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1

u8 code T_COM[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};      //??

u8 display[][8]=
{
	{1,3,17,0,3,17,0,5},//时间界面
	{12,16,2,8,17,2,35,2},//温度回显
	{18,16,6,8,17,5,32,4},//湿度回显
	{15,},//时间回显
	{16},//参数界面
	{16},//温湿度界面
};

u8 timer100ms=0;
u8 timer10ms=0;
u8 *digs=&display;
u8 n=0;
u8 led=0xff;
u8 key_value,key_state=0;
u8 key_values[4][4]=
{
	7,11,15,19,
	6,10,14,18,
	5,9,13,17,
	4,8,12,16,
};


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

void led_dis()
{
	P0=led;
	P2|=0X80;
	P2&=0X1F;
}

void key_scan()
{
	u8 x,y;
	
	P3=0X0F;
	P4=0X00;
	if(~P3&0X0F)
	{
		if(key_state<255)
			key_state++;
		
		if(P30==0)
			x=0;
		if(P31==0)
			x=1;
		if(P32==0)
			x=2;
		if(P33==0)
			x=3;
		
		P3=0XF0;
		P4=0XFF;
		if(P44==0)
			y=0;
		if(P42==0)
			y=1;
		if(P35==0)
			y=2;
		if(P34==0)
			y=3;
		
		key_value=key_values[x][y];
	}
	else
	{
		key_value=0;
		key_state=0;
	}
}

unsigned int ne555()
{
	unsigned int temp;
	
	TR0=0;
	temp=((unsigned int)TH0<<8)|TL0;
	
	TH0=0;
	TL0=0;
	TR0=1;
	
	return temp;
}

void Timer0_Init(void)		//1??@12.000MHz
{
	AUXR |= 0x80;			//?????1T??
	TMOD &= 0xF0;			//???????
	TMOD |=0X04;
	TL0 = 0;				//???????
	TH0 = 0;				//???????
	TF0 = 0;				//??TF0??
	TR0 = 1;				//???0????
}

void Timer1_Init(void)		//1??@12.000MHz
{
	AUXR |= 0x40;			//?????1T??
	TMOD &= 0x0F;			//???????
	TL1 = 0x20;				//???????
	TH1 = 0xD1;				//???????
	TF1 = 0;				//??TF1??
	TR1 = 1;				//???1????
	EA=1;
	ET1=1;
}

void Timer1_isr() interrupt 3
{
	timer10ms++;
	read_ds1302();
	seg_dis();
	led_dis();
}