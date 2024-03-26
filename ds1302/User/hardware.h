#ifndef __HARDWARE_H__
#define __HARDWARE_H__

#include <STC15F2K60S2.H>

extern unsigned char code seg[];
extern unsigned int timer250ms;
extern unsigned char P_DIG;
extern unsigned char *digs;
extern unsigned char dis_buf[][8];
extern unsigned char com[];
extern unsigned char time_digs[];

void Timer1Init();
void timer1_isr();
void Close();
void DIGs_show();

#endif