#include "hardware.h"

unsigned char com[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};//�����λ

/*************  ���س�������    **************/
unsigned char code seg[]={                       //��׼�ֿ�
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
//black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
    0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
    0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46};    //0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1

void Timer1Init()		//1����@12.000MHz
{
	AUXR |= 0x40;			//��ʱ��ʱ��1Tģʽ
	TMOD &= 0x0F;			//���ö�ʱ��ģʽ
	TL1 = 0x20;				//���ö�ʱ��ʼֵ
	TH1 = 0xD1;				//���ö�ʱ��ʼֵ
	TF1 = 0;				//���TF1��־
	TR1 = 1;				//��ʱ��1��ʼ��ʱ
	ET1 = 1;
	EA = 1;
}		

void Close()
{
	P2=0x00;
	
	P0=0xff;
	P2|=0x80;  //�ر�Led
	P2&=0x1f;
	
	P0=0x00;
	P2|=0XC0; //�رռ̵�����������
	P2&=0x1f;
}

unsigned char dis_buf[][8]=
{
{16,16,16,16,16,16,16,16},//test
{16,16,17,16,16,17,16,16},//ʱ��
{16,16,16,16,16,16,16,16},//e2prom
{16,16,16,16,16,16,16,0x0C},//temperature
{0x0F,16,16,16,16,16,16,16},//ne555_frep
}	;

//�������ʾ 2
unsigned char *digs;
unsigned int timer10ms=0;
unsigned int timer250ms=0;
unsigned int timer1000ms=0;
void DIGs_show()
{
	static unsigned char P_DIG=0;
	
	Close();
	
	P0=~seg[digs[P_DIG]];//��ѡ
	P2|=0xE0;
	P2&=0x1F;
	
	P0=com[P_DIG];//λѡ
	P2|=0xC0;
	P2&=0x1F;
	
	if(++P_DIG>=8)
	{
		P_DIG=0;
	}
}

void timer1_isr() interrupt 3
{
	timer10ms++;
	timer250ms++;
	timer1000ms++;
	DIGs_show();
}







