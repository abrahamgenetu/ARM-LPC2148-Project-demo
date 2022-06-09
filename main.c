/*****************************************************
       CALCULATOR DEMO USING KEYPAD AND LCD 16X2
******************************************************/
#include <lpc214x.h>
#include <stdio.h>
#include "LCD.h"
#include "KEYPAD.h"
#include "PLL.h"
#include "TIMER.h"

int main (void)
{   char key;                             //the variable that holds value returned from the keypad.
	  char RESULT[3];                        // variable that hold the final result changed to char
		int  iresult1=0,iresult2=0,num1=0,num2=0;
		float fresult,result;
	  set_configuration(); 
		
	  //Initializing the lcd to start
		lcd_init();
	  lcd_print("CALCULATOR DEMO");//print string
	  lcd_cmd(0x01);//clearing the lcd using
	
	  lcd_print("");//print string
	  lcd_cmd(0x01);//clearing the lcd using
		while(1)//always
			{
				
				//---------------------------------------------------------
				lcd_cmd(0x80);//first line of first row
				lcd_print("ENTER 1ST NO:");//requesting user to enter
				key= get_key();//copying  value of key
				lcd_cmd(0xc0);//new line or second row
				lcd_char(key);//send to lcd
				delay_milli(30);	//delay using atimer 
				lcd_cmd(0x01);	
				num1=get_num(key);//conversion
				
				//------------------------------------------------------------
				lcd_cmd(0x80);
				lcd_print("ENTER 2ND NO:");
				key= get_key();
				lcd_cmd(0xc0);
				lcd_char(key);
				delay_milli(30);
				lcd_cmd(0x01);	
				num2=get_num(key);
				key=get_key();
				lcd_char(key);
				
        //------------------------------------------------------
		  	// choosing the operation
				lcd_cmd(0x80);
				lcd_print("+ SUM");
				lcd_cmd(0x87);
				lcd_print("- MIN");
				lcd_cmd(0xC0);
				lcd_print("* MUL");
				lcd_cmd(0xC7);
				lcd_print("/ DIV > ");
				delay_milli(10);	
				
			
				
				//----------------------------------------------------------
			switch (key)
				// while((func!=1)|(func!=2)|(func!=3)|(func!=4));
					{
					case '+':result=num1+num2;
						break;
					case '-':result=num1-num2;
						break;
					case '*':result=num1*num2;
						break;
					case '/':
					        result=num1/num2;
						   
						break;
					default:
					delay(300);
					lcd_cmd(0x80);
					lcd_print("WRONG FUNCTION");
					delay(200);
					lcd_cmd(0x01);

					continue;
				}
					//---------------------------------------------
				  //after excution result 
				lcd_cmd(0x01);
				lcd_cmd(0x80);
				iresult1 = (int) result; 
				fresult  = result - iresult1;
				iresult2 = (int)100*fresult;// 1000*fval to get 3 digits after the decimal
				sprintf(RESULT,"%d.%d",iresult1,iresult2); 
				lcd_print("RESULT=");
				lcd_print(RESULT);
				delay_milli(200);
				lcd_cmd(0x01);
		}
	}	
