#include "keypad.h"								// include the header file

void keypad_init()										// definition of initial function
{
	set_port_direction(OI,~comp);						// make portD input & output
	set_port_value(OI,0xFF);							// set initial value for portD
}

char keypad_scan()										// definition for function get the pressed key 
{
	char key;											// char to store the pressed key
	char counter;										// counter for count rowe
	for(counter=start;counter<end;counter++)			// for loop for set row = 0
	{
		set_port_value(OI,0xFF);						// set the value of output port = 11111111
		clear_pin_value(OI,counter);					// put 0 on pin number = counter in output port
		key=(read_port_value(OI))&comp;					// read the value of coloumns 
		if(key!=comp) 									// key!=00001111 means that key pressed
		{
			while(((read_port_value(OI))&comp)!=comp); 	// don't exit until person raise hand from button
			break;										// exit from for loop when key not pressed
		}
	}
	if(counter==end)									// counter=8 when button not pressed
	{
		return 0;
	}
	switch(counter)										// switch case if button pressed
	{
		case first: 	
			switch(key)									// switch case for row 0
			{
				case out1:								// if coloumn pins = 1110
					return r0c0;
				break;
				case out2:								// if coloumn pins = 1101
					return r0c1;
				break;
				case out3:								// if coloumn pins = 1011
					return r0c2;
				break;
				case out4:								// if coloumn pins = 0111
					return r0c3;
				break;
			}
		break;											// exit from case 4
		case second: 									// switch case for row 2
			switch(key)
			{
				case out1:
					return r1c0;
				break;
				case out2:
					return r1c1;
				break;
				case out3:
					return r1c2;
				break;
				case out4:
					return r1c3;
				break;
			}
		break;											// exit from case 5
		case third: 									// switch case for row 3
			switch(key)
			{
				case out1:
					return r2c0;
				break;
				case out2:
					return r2c1;
				break;
				case out3:
					return r2c2;
				break;
				case out4:
					return r2c3;
				break;
			}
		break;											// exit from case 6
		case fourth: 									// switch case for row 4
			switch(key)
			{
				case out1:
					return r3c0;
				break;
				case out2:
					return r3c1;
				break;
				case out3:
					return r3c2;
				break;
				case out4:
					return r3c3;
				break;									// exit from case 7
			}
		break;											// exit from switch(counter)
	}
}
