#include "hardware.h"

unsigned char com[9]={0,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};//数码管位

/*************  本地常量声明    **************/
unsigned char code seg[]={                       //标准字库
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
//black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
    0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
    0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46};    //0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1

		
void Timer1Init()		//1毫秒@12.000MHz
{
	AUXR |= 0x40;			//定时器时钟1T模式
	TMOD &= 0x0F;			//设置定时器模式
	TL1 = 0x20;				//设置定时初始值
	TH1 = 0xD1;				//设置定时初始值
	TF1 = 0;				//清除TF1标志
	TR1 = 1;				//定时器1开始计时
	ET1 = 1;
	EA = 1;
}		

void Close()
{
	P2=0x00;
	
	P0=0xff;
	P2|=0x80;  //关闭Led
	P2&=0x1f;
	
	P0=0x00;
	P2|=0XC0; //关闭继电器、蜂鸣器
	P2&=0x1f;
}

void seg_dis(unsigned char m,unsigned char n)
{
	Close();
	
	P0=~seg[m];
	P2|=0xe0;
	P2&=0x1f;
	
	P0=com[n];
	P2|=0XC0;
	P2&=0X1f;
}



unsigned char key_values[4][4]=
{
	4,5,6,7,
	8,9,10,11,
	12,13,14,15,
	16,17,18,19
};
unsigned char key_value;
unsigned int key_state=0;
unsigned char timer10ms=0;
void get_key()
{
	unsigned char X,Y;
	P3=0x0F;
	P4=0x00;
	if(~P3&0x0f)
	{
	 if(key_state<255)
		 key_state++;
	 
	 if(P33==0)
	 {
		 Y=0;
	 }
	 if(P32==0)
	 {
		 Y=1;
	 }
	 if(P31==0)
	 {
		 Y=2;
	 }
	 if(P30==0)
	 {
		 Y=3;
	 }
	 
	 P3=0xF0;
	 P4=0xFF;
	 if(P44==0)
	 {
		 X=0;
	 }
	 if(P43==0)
	 {
		 X=1;
	 }
	 if(P35==0)
	 {
		 X=2;
	 }
	 if(P34==0)
	 {
		 X=3;
	 }
	 key_value=key_values[X][Y];
	}
	else
	{
		key_value=0;
		key_state=0;
	}
}

void timer1_isr() interrupt 3
{
	timer10ms++;
}







