#ifndef __HARDWARE_H__
#define __HARDWARE_H__

typedef unsigned char u8;

#include <STC15F2K60S2.H>
#include "onewire.h"
#include "ds1302.h"
#include "iic.h"
#include "intrins.h"

extern u8 code t_display[];
extern u8 code T_COM[];
extern u8 display[][8];
extern u8 timer100ms;
extern u8 timer10ms;
extern u8 *digs;
extern u8 n;
extern u8 led;
extern u8 key_value,key_state;
extern u8 key_values[4][4];

void close();
void seg_dis();
void led_dis();
void key_scan();
unsigned int ne555();
void Timer0_Init(void);
void Timer1_Init(void);
void Timer1_isr();
#endif