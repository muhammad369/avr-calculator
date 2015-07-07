#include <avr\io.h>

#ifndef dio
#define dio

char read_port_value(char port);						// return port value as character

void set_port_direction(char port,char x);				// specify the direction of port (input or outport)

void set_port_value(char port , char x);				// output specific value on a port

void set_pin_direction(char port,int x);				// specify the dierection of pin on specific port

void set_pin_value(char port , int x);					// output 1 on a specific pin on port

void clear_pin_value(char port , int x);				// output 0 on a specific pin on port

void toggle_pin_value(char port , int x);				// change the staus of pin value


#endif
