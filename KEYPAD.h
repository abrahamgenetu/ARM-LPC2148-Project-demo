//HERE IS THE KEYPAD DEMO HEADER FILES
//--------------------------------------------------------
#include <lpc214x.h>
#define r1 (1<<16)
#define r2 (1<<17)
#define r3 (1<<18)
#define r4 (1<<19)
//  col
#define c1 (1<<20)
#define c2 (1<<21)
#define c3 (1<<22)
#define c4 (1<<23)
void delay(unsigned int time); // variable delay function

int get_num(unsigned char);
unsigned char get_key(void);
void keypad_delay(void);


void keypad_delay(void)
{
	unsigned int t1,t2;
	for(t1=0;t1<300;t1++)
	for(t2=0;t2<1000;t2++);
}
unsigned char get_key (void)
	{
	unsigned char key;
	IOCLR1|=(c1|c2|c3|c4|r1|r2|r3|r4);
	while(1)
	{
		IOCLR1|=c1;
		IOSET1|=(c2|c3|c4); // first column = 0
		if((IOPIN1&r1)==0)
		{
			key='7';
			keypad_delay();
			return key;
		}
		else if((IOPIN1&r2)==0)
			{
			key='8';
			keypad_delay();
			return key;
		}
		else if((IOPIN1&r3)==0)
		 {
			key='9';
			keypad_delay();
			return key;
			}
		else if((IOPIN1&r4)==0)
		{
			key='/';
			keypad_delay();
			return key;
		}
		IOCLR1|=c2;
		IOSET1|=(c1|c3|c4); //second column = 0
		if((IOPIN1&r1)==0)
		{
			key='4';
			keypad_delay();
			return key;
			}
		else if((IOPIN1&r2)==0)
		{
		key='5';
		keypad_delay();
		return key;
		}
		else if((IOPIN1&r3)==0)
		{
			key='6';
			keypad_delay();
			return key;
		}
		else if((IOPIN1&r4)==0)
		{
			key='*';
			keypad_delay();
			return key;
		}
		IOCLR1|=c3;
		IOSET1|=(c1|c2|c4); //third column = 0
		if((IOPIN1&r1)==0)
		{
			key='1';
			keypad_delay();
			return key;
		}
		else if((IOPIN1&r2)==0)
		{
			key='2';
			keypad_delay();
			return key;
		}
		else if((IOPIN1&r3)==0)
		{
			key='3';
			keypad_delay();
			return key;
		}
		else if((IOPIN1&r4)==0)
		{
			key='-';
			keypad_delay();
			return key;
		}
		
		IOCLR1|=c4;
		IOSET1|=(c1|c2|c3); //forth column = 0
		if((IOPIN1&r1)==0)
		{
			//lcd_cmd(0x01);
			keypad_delay();
		}
		else if((IOPIN1&r2)==0)
		{
			key='0';
			keypad_delay();
			return key;
		}
		else if((IOPIN1&r3)==0)
		{
			key='=';
			keypad_delay();
			return key;
		}
		else if((IOPIN1&r4)==0)
		{
		  key='+';
			keypad_delay();
			return key;
			}
		}
}


	int get_num(unsigned char ch)         //convert char into int
{
    switch(ch)
    {
    case '0': return 0; break;
    case '1': return 1; break;
    case '2': return 2; break;
    case '3': return 3; break;
    case '4': return 4; break;
    case '5': return 5; break;
    case '6': return 6; break;
    case '7': return 7; break;
    case '8': return 8; break;
    case '9': return 9; break;
    }
    return 0;
}