#ifndef __HARDWARE_H__
#define __HARDWARE_H__

typedef unsigned char u8;

extern u8 code t_display[];
extern u8 code T_COM[];
extern u8 display[][8];
extern u8 *digs;
extern u8 n;

void close();
void seg_dis();


#endif