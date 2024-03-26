#include <STC15F2K60S2.H>
#include "hardware.h"

void main()
{
	int num=0;
	Timer1Init();
	
	while(1)
	{

	if(timer10ms>=10)
	{
		timer10ms=0;
			
		get_key();
		
		if(key_value==5&&key_state==2)
		  num++;
		if(key_value==4&&key_state==2)
			num--;
		if(key_value==6&&key_state==2)
		  num+=2;
		if(key_value==7&&key_state==2)
			num-=2;
	}
	if(num/10/10)
	seg_dis(num/10/10,1);
	if(num/10%10)
	seg_dis(num/10%10,2);
	if(num%10)
	seg_dis(num%10,3);
}
}