#ifndef __HARDWARE_H__
#define __HARDWARE_H__

#include <STC15F2K60S2.H>

extern unsigned char code seg[];
extern unsigned char key_values[4][4];
extern unsigned char key_value;
extern unsigned int key_state;
extern unsigned char timer10ms;

void Timer1Init();
void timer1_isr();
void Close();
void seg_dis(unsigned char m,unsigned char n);
void get_key();

#endif