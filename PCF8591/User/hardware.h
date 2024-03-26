#ifndef __HARDWARE_H__
#define __HARDWARE_H__

#include <STC15F2K60S2.H>

extern unsigned char com[];
extern unsigned char code seg[];
extern unsigned char dis_buf[][8];
extern unsigned char *digs;
extern unsigned char timer10ms;

void DIGs_show();	
void Timer1Init();
void Close();
void timer1_isr();

	
#endif