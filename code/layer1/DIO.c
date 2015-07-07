#include "DIO.h"

/*********************** functions definitions *******************************/

void set_port_direction(char port,char x)					// port=port name          x=direction of pins as 0xF0  or 0b11110000
{
	switch(port)
		{
			case 'A':
						DDRA=x;
			break;
			case 'B':
						DDRB=x;
			break;
			case 'C':
						DDRC=x;
			break;
			case 'D':
						DDRD=x;
			break;
		}
}

/********************************************************************************/

void set_port_value(char port , char x)					// port=port name          x=port value
{
	switch(port)
		{
			case 'A':
						PORTA=x;
			break;
			case 'B':
						PORTB=x;
			break;
			case 'C':
						PORTC=x;
			break;
			case 'D':
						PORTD=x;
			break;
		}
}

/********************************************************************************/

char read_port_value(char port)				// port=port name
{
	switch(port)
		{
			case 'A':
						return PINA;
			break;
			case 'B':
						return PINB;
			break;
			case 'C':
						return PINC;
			break;
			case 'D':
						return PIND;
			break;
		}
}
/********************************************************************************/
void set_pin_direction(char port,int x)			// port=port name including pin          x=pin number in the port
{
	switch(port)
		{
			case 'A':
						DDRA|=(1<<x);
			break;
			case 'B':
						DDRB|=(1<<x);
			break;
			case 'C':
						DDRC|=(1<<x);
			break;
			case 'D':
						DDRD|=(1<<x);
			break;
		}
}
/********************************************************************************/

void set_pin_value(char port , int x)	//x=pin number in the port     pin=1
{
	switch(port)
		{
			case 'A':
						PORTA|=(1<<x);
			break;
			case 'B':
						PORTB|=(1<<x);
			break;
			case 'C':
						PORTC|=(1<<x);
			break;
			case 'D':
						PORTD|=(1<<x);
			break;
		}
}
/********************************************************************************/

void clear_pin_value(char port , int x)					// port=port name including pin          x=pin number in the port		pin=0
{
	switch(port)
		{
			case 'A':
						PORTA&=~(1<<x);
			break;
			case 'B':
						PORTB&=~(1<<x);
			break;
			case 'C':
						PORTC&=~(1<<x);
			break;
			case 'D':
						PORTD&=~(1<<x);
			break;
		}
}
/*******************************************************************************/

void toggle_pin_value(char port , int x)				// port=port name including pin          x=pin number in the port
{
	switch(port)
		{
			case 'A':
						PORTA^=(1<<x);
			break;
			case 'B':
						PORTB^=(1<<x);
			break;
			case 'C':
						PORTC^=(1<<x);
			break;
			case 'D':
						PORTD^=(1<<x);
			break;
		}
}
