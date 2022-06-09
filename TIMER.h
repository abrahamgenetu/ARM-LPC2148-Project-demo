#include <LPC214X.h>

void delay_milli(unsigned int milliseconds) ;
void delay_micro(unsigned int microseconds) ;


void delay_milli(unsigned int milliseconds)
{
		//Using Timer0
		T0CTCR = 0x00 ; // configure T0 as Timer
		T0PR = 60000-1 ;
		T0TC = 0; //Reset Timer
		T0TCR = 0x01; //Enable timer
		while(T0TC < milliseconds);
		//wait until timer reaches the desired delay
		T0TCR = 0x00; //Disable timer
}
void delay_micro(unsigned int microseconds)
{
		//Using Timer0
		T0CTCR = 0x00 ; // configure T0 as Timer
		T0PR = 60-1 ;
		T0TC = 0; //Reset Timer
		T0TCR = 0x01; //Enable timer
		while(T0TC < microseconds);
		//wait until timer reaches the desired delay
		T0TCR = 0x00; //Disable timer
}