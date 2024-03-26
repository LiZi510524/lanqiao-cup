#include <STC15F2K60S2.H>
#include "hardware.h"

void Timer0_Init();
void Timer1_Init();
void Timer1_ISR();

unsigned int timer100ms=0;
unsigned int ne555=0;


void main()
{
	
	close();
	Timer0_Init();
	Timer1_Init();
	
	while(1)
	{
		
		
		if(ne555>100000)
			digs[2]=ne555/100000;
		else
			digs[2]=16;
		if(ne555>10000)
			digs[3]=ne555/10000%10;
		else
			digs[3]=16;
		if(ne555>1000)
			digs[4]=ne555/1000%10;
		else
			digs[4]=16;
		if(ne555>100)
			digs[5]=ne555/100%10;
		else
			digs[5]=16;
		digs[6]=ne555/10%10;
		digs[7]=ne555%10;
	}
}

void Timer0_Init()		//100??@12.000MHz
{
	AUXR |= 0x80;			//?????1T??
	TMOD &= 0xF0;			//???????
	TMOD|=0X04;
	TL0 = 0;				//???????
	TH0 = 0;				//???????
	TF0 = 0;				//??TF0??
	TR0=1;
}

void Timer1_Init()		//1??@12.000MHz
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

void Timer1_ISR() interrupt 3
{
	seg_dis();
	timer100ms++;
	
	if(timer100ms>=100)
		{
			timer100ms=0;
			TR0=0;
			ne555=((unsigned int)TH0<<8)|TL0;
			ne555*=10;
			TH0 = 0;				
	    TL0 = 0;		
			TR0=1;
		}
}
