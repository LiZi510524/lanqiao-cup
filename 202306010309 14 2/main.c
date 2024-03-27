#include <STC15F2K60S2.H>
#include "hardware.h"

void main()
{
	u8 mode_1=0;
  u8 mode_2=0;
	
	close();
	write_ds1302();
	Timer0_Init();
	Timer1_Init();
	
	while(1)
	{
		if(timer10ms>=10)
		{
			timer10ms=0;
			key_scan();
		}
		if(key_value==4&&key_state==2)
		{
			if(mode_1<2)
				mode_1++;
			else
			{
				mode_1=0;
				mode_2=0;
			}
		}
		
		switch(mode_1)
		{
			case '0':
				digs=display[0];
				break;
			
			case '1':
				digs=display[1];
				if(key_value==5&&key_state==2)
				{
					if(mode_2<2)
						mode_2++;
					else
						mode_2=0;
				}
				
				switch(mode_2)
				{
					case '0':
						digs=display[2];
						break;
					case '1':
						digs=display[3];
						break;
					case '2':
						digs=display[4];
						break;
				}
				break;
				
			case '2':
				digs=display[5];
				break;
		}
	}

}



