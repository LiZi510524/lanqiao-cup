#include <STC15F2K60S2.H>
#include "hardware.h"
#include "onewire.h"

void main()
{
	float temp_temperature;
	Timer1Init();
	digs=&dis_buf[3];
	while(1)
	{
		if(timer250ms>=250)
		{
			timer250ms=0;
		  temp_temperature=rd_temperature();
		
		  digs[0]=(unsigned int)temp_temperature/10;
		  digs[1]=(unsigned int)temp_temperature%10+32;
		  digs[2]=(unsigned int)(temp_temperature*10)%10;
		  digs[3]=(unsigned int)(temp_temperature*100)%10;
		  digs[4]=(unsigned int)(temp_temperature*1000)%10;
		  digs[5]=(unsigned int)(temp_temperature*10000)%10;
		}
	}
	
}