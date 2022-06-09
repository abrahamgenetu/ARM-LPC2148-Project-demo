#include <LPC214X.h>

void initPLL(void);

void initPLL(void)
{
		PLL0CON = 0x01 ; // Enable PLL
		PLL0CFG = 0x24 ; // Set Up PLL for CClk = 60MHz
		PLL0FEED = 0xAA; 
		PLL0FEED = 0x55; // Apply Feed Sequence
		while( (PLL0STAT & (0x01<<10)) ==0 );
		// Check Whether CCO Latched
		PLL0CON = 0x03; // Enable & Connect PLL
		PLL0FEED = 0xAA; PLL0FEED = 0x55; // Apply Feed Sequence
		VPBDIV=0x01; // Pclk is same as Cclk (60 MHz)
}