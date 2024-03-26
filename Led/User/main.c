#include <STC15F2K60S2.H>//引用头文件

typedef unsigned int unit;

/*void Delay(unit x)	//@12.000MHz
{
	unsigned char data i, j;
while(x--)
{
	i = 4;
	j = 205;
	do
	{
		
	 while (--j);
	} while (--i);
}
}
*/

void Delay(unsigned int a)	//@12.000MHz     //延时函数
{
	unsigned int b;
	while(a--)
	{
		for(b=0;b<125;b++);
	}
}


sbit DIOLA=P2^5;

sbit Led1=P1^0;
sbit Led2=P1^1;
sbit Led3=P1^2;
sbit Led4=P1^3;
sbit Led5=P1^4;
sbit Led6=P1^5;
sbit Led7=P1^6;
sbit Led8=P1^7;

void main()
{
	while(1)
	{
		DIOLA=1;
		//P1=0x5F; //0101 1111  0为亮 1为熄
		//P1=0x0;  //全亮
		//Led1=0;
		Delay(1000);
		//Led1=1;
		//Led3=0;
		Delay(1000);
		//Led3=1;
		Led5=0;
		Delay(1000);
		Led5=1;
		Led7=0;
		Delay(1000);
		Led7=1;
	}
}
