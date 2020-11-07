#include <reg51.h>
sbit KEY_UP = P3^3;
sbit KEY_DN = P3^2;
sbit KEY_SET = P3^4;

typedef unsigned char uchar;
typedef unsigned int uint;

void getkey();
void delay(uint t);

uint i = 0, t = 0;
uchar code table[]={
  	0x3F,  //"0"
    0x06,  //"1"
    0x5B,  //"2"
    0x4F,  //"3"
    0x66,  //"4"
    0x6D,  //"5"
    0x7D,  //"6"
    0x07,  //"7"
    0x7F,  //"8"
    0x6F,  //"9"
	};
main()
{
	while(1)
	{
		KEY_UP = 1;
		KEY_DN = 1;
		KEY_SET = 1;
		P0 = table[i];
		getkey();
		if(i >= 10 || i < 0)
		{
			i = 0;
		}
	}
}

void getkey()
{
	if(KEY_UP == 0)
	{
		delay(5);
		if(KEY_UP == 0)
		{
			i++;
			while(1)
			{
				if(KEY_UP == 1)
				{
					break;
				}
			}
		}
	}
	if(KEY_DN == 0)
	{
		delay(5);
		if(KEY_DN == 0)
		{
			i--;
			while(1)
			{
				if(KEY_DN == 1)
				{
					break;
				}
			}
		}
	}
	if(KEY_SET == 0)
	{
		delay(5);
		if(KEY_SET == 0)
		{
			i = 0;
			while(1)
			{
				if(KEY_DN == 1)
				{
					break;
				}
			}
		}
	}
}

void delay(uint t)
{
	unsigned x,y;
	for(x=t;x>0;x--)
	{
		for(y=124;y>0;y--);
	}
}