/*
HERE IS THE LCD DEMO HEADER FILES
******************************************************/
#include <lpc214x.h>
#include <stdio.h>
#define LCD (0xff<<8)
#define RS (1<<16)
#define RW (1<<17)
#define EN (1<<18)

void delay(unsigned int time); // variable delay function
void lcd_init(void);
void lcd_print(char *str);
void lcd_cmd(unsigned char command);
void lcd_char(unsigned int data);
void set_configuration();

void set_configuration()
{
	  PINSEL0 = 0x00000000;//DEFALUT GPIO FUNCTIONING 
		PINSEL1 = PINSEL0;
		IODIR1 = 0x00f00000;
	   for(int i=8; i<19;i++)
	    {
				IO0DIR |= (1<<i);
			}
}

void lcd_cmd(unsigned char command)
{
	IO0CLR|=(RS|RW|EN|LCD);
	IO0SET|=(command<<8);
	IO0CLR|=RS;  //comand
	IO0CLR|=RW;  
	IO0SET|=EN;
	delay(2);
	IO0CLR|=EN;
	delay(3);
}
void lcd_char(unsigned int data)
{
	IO0CLR|=(RS|RW|EN|LCD);
	IO0SET|=(data<<8);
	IO0SET|=RS; ///data
	IO0CLR|=RW;  // write lcd
	IO0SET|=EN;  
	delay(2);
	IO0CLR|=EN;
	delay(3);
}
void lcd_print(char *str) //string print
{
	while(*str!='\0')//untill the string looping gets null
	{
		lcd_char(*str);//send each char to lcd dat
		str++;
	}
}
void lcd_init(void)
{
	delay(5);
	lcd_cmd(0X38);//8 bit lcd
	lcd_cmd(0X0f);//cursor blinking 
	lcd_cmd(0X06);//entry mode
	lcd_cmd(0X01);//clear
	delay(5);
	lcd_cmd(0X80);//new line
}
void delay(unsigned int time) // variable delay function
{
	unsigned int t1,t2;
	for(t1=0;t1<time;t1++)
		for(t2=0;t2<1275;t2++);
}

