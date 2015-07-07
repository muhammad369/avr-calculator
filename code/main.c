/*
 * main.c
 *
 *      Author: Ali
 */

#include "layer2/keypad.h"
#include "layer2/kitlcd.h"
#include "layer3/calc.h"
#include "layer3/stack.h"
#include <string.h>

#define digitsLength 8

#define debug
#ifdef debug
#include "layer2/uart.h"
char dgts[10]="0123456789";
char ops[4]="+-X/";
#endif

#define _log(x) UART_SendStr(x);
#define _log1(x) UART_TRANSMIT(x);

//globals
stack_ref sd1 , sd2 ;
int state, operator=0;
long result;
int value;



void showError()
{
	_log("error\r\0");
	//buzzer
	set_pin_value(outport,3);
	_delay_ms(500);
	clear_pin_value(outport,3);

}

void clear()
{
	state=0;
	stack_Clear(sd1);
	stack_Clear(sd2);
	LCD_Clear();
	LCD_Gotoxy(0,0);
}

void calculateResult()
{
	long x,y;
	if(stack_isempty(sd1))
	{
		x=result;
	}
	else
	{
		x=get_value_of_stack(sd1);
	}
	y=get_value_of_stack(sd2);

	//do the operation
	switch (operator)
	{
	case 0:
		result = x + y;
		break;
	case 1:
		result = x-y;
		break;
	case 2:
		result = x*y;
		break;
	case 3:
		result = x/y;
		break;
	}

	//display
//	if(stack_isempty(sd1))
//	{
		LCD_Clear();
		LCD_Gotoxy(0,0);
		char* d=(char*)malloc(digitsLength);
		LCD_SendStr(itoa(result, d, 10));

		_log("operator \0") _log1(ops[operator]) _log("\r\0")
		_log("result \0") _log(d) _log("\r\0")
//	}
//	else
//	{
//		LCD_Clear();
//		LCD_Gotoxy(0,0);
//		char* d1=(char*)malloc(digitsLength);
//		LCD_SendStr(itoa(x, d1, 10));
//		LCD_SendData(ops[operator]); //error send the op as char not int
//		char* d2=(char*)malloc(digitsLength);
//		LCD_SendStr(itoa(y, d2, 10));
//	}

	//clear stacks
	stack_Clear(sd1);
	stack_Clear(sd2);
}



void keyPressed(char key)
{
	//the clear button
	if (key == 'C')
	{
		clear();
		_log("lcd cleared\r\0");
		return;
	}
	//
	switch (state)
	{
	case 0:

		if ((value=getDigit(key)) != -1) //digit
		{_log("number\r\0")
			//check stack, if full show errer
			if (! stack_isfull(sd1))
			{
				stack_push(sd1,value);
				LCD_SendData(key);
			}
			else
			{
				showError();
				_log(" stack full\r\0");
			}
		}
		else if(getOperator(key) != -1) //operator
		{
			operator=getOperator(key);
			_log(" operator \0") _log1(ops[operator]) _log("\r\0")
			if(stack_isempty(sd1))
			{

				showError(); _log("operator can't be the 1st input\r\0")
			}
			else
			{
				state=1;
				LCD_SendData(key);
			}
		}
		else
		{
			showError();
		}
		_log("state \0")  _log1(dgts[state]); _log("\r\0")
		break;
	case 1:

		if ((value=getDigit(key)) != -1) //digit
		{
			//check stack, if full show errer
			if (! stack_isfull(sd2))
			{
				stack_push(sd2,value);
				state=2;
				LCD_SendData(key);
			}
			else
			{
				showError();
			}
		}
		else{
			showError();
		}
		_log("state \0") _log1(dgts[state]); _log("\r\0")
		break;
	case 2:

		if ((value=getDigit(key)) != -1) //digit
		{
			//check stack, if full show errer
			if (! stack_isfull(sd2))
			{
				stack_push(sd2,value);
				LCD_SendData(key);
			}
			else
			{
				showError();
			}
		}
		else if((getOperator(key)) != -1) //error setting the new operator before calc result
		{   //operator
			state=3;
			calculateResult();
			operator = getOperator(key);
		}
		else if(key == '=')
		{
			state = 4;
			calculateResult();
		}
		else
		{
			showError();
		}
		_log("state \0") _log1(dgts[state]); _log("\r\0")
		break;
	case 3:

		if ((value=getDigit(key)) != -1) //digit
		{
			//check stack, if full show errer
			if (! stack_isfull(sd2))
			{
				stack_push(sd2,value);
				state = 2;
			}
			else
			{
				showError();
			}
		}
		else
		{
			showError();
		}
		_log("state \0") _log1(dgts[state]); _log("\r\0")
		break;
	case 4:

		if((getOperator(key)) != -1)
		{   //operator

			operator = getOperator(key);
			LCD_SendData(key);
			state=3;
		}
		else
		{
			showError();
		}
		_log("state \0") _log1(dgts[state]); _log("\r\0")
		break;
	}
}


void main()
{

	LCD_init();
	keypad_init();
	#ifdef debug
	UART_init(51);
	UART_SendStr("calculator log is working\r\n \0");
	#endif
	sd1 = new_stack(digitsLength);
	sd2 = new_stack(digitsLength);
	state=0;


	char x;
	while(1)
	
		//
		x=keypad_scan();								// read char from keypad
		if(x!=0)
		{
			keyPressed(x);
		}

	}
}
