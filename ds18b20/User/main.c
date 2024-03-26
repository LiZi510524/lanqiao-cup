#include <STC15F2K60S2.H>
#include "hardware.h"

void main()
{
	unsigned char p_time_dig=0;
	//Ð´ÈëÊ±¼ä
	while(1)
	{
		Timer1Init();
		
	
		if(timer10ms>=1)
		{
			timer10ms=0;
		  DIGs_show();
		}
	}
	
}