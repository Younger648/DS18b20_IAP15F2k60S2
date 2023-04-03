#include "head.h"



void main()
{
	Timer0Init();
    
	while(1)
	{
		ds18b20_config();
	}

}





