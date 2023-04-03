#include "head.h"

unsigned char code SMG_Table[17] = 
{
0xc0, //0
0xf9, //1
0xa4, //2
0xb0, //3
0x99, //4
0x92, //5
0x82, //6
0xf8, //7
0x80, //8
0x90, //9
0x88, //A
0x83, //b
0xc6, //C
0xa1, //d
0x86, //E
0x8e, //F
0x7f
};

unsigned char code SMG_adr[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

unsigned int temperature;


void SMG_show()
{
	unsigned char adrr,datt;
	
	static char i;
	i ++;
	if(i == 6)
	i = 1;
	switch(i)
	{
		case 1:
			adrr = 0;
			datt = 10;
		break;
		
		case 2:
			adrr = 5;
			datt = temp / 100;
		break;
		
		case 3:
			adrr = 6;
			datt = 16;
		break;
				
		case 4:
			adrr = 6;
			datt = temp / 10 % 10;
		break;
						
		case 5:
			adrr = 7;
			datt = temp % 10;
		break;
	
	}
	SMG_config(SMG_adr[adrr],SMG_Table[datt]);

}