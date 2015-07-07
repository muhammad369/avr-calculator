#include "kitlcd.h"
/*************************** Functions definitions **********************************/
 
void LCD_init() 						    	// fuction for intialize 
{
	set_port_direction(outport,0xFF);				// intialize output port
	LCD_SendCmd(0x02); 						    	// to initialize LCD in 4-bit mode.
	LCD_SendCmd(0x28); 						    	// to initialize LCD in 2 lines, 5X7 dots and 4bit mode.
	LCD_SendCmd(0x0C);						      	// make lcd ready for write
	LCD_SendCmd(0x06);						        // increment cursor to right
	LCD_SendCmd(0x80);						     	// start form address 80 @ x in row 0
	
}
 
void LCD_SendCmd(char cmd_value)		  	        // send commands function (actually sending occur @ function LCDCmd)
{
	char cmd_value1;
 	cmd_value1 = cmd_value & 0xF0;             	    // i send the higher bits only (PB7 -> PB4)
    LCDCmd(cmd_value1); 				  	        // send to LCD
 
	cmd_value1 = ((cmd_value<<4) & 0xF0); 	        // shift the bits (PB3->PB0) and send them to LCD
	LCDCmd(cmd_value1); 					        
} 
 
 
void LCD_SendData(char data_value)			  	    // send data function the same as command (actually sending occur @ function LCDData)
{
	char data_value1;						
 	data_value1=data_value&0xF0;			
	LCDData(data_value1);
 	data_value1=((data_value<<4)&0xF0);
	LCDData(data_value1);
	_delay_ms(200);
}
 
void LCDCmd(char cmdout)			       	   		// send command to LCD
{
	set_port_value(outport,cmdout);				    // output cmdout on output port
	clear_pin_value(outport,rs);					// clrbit rs=0 (send command)
	set_pin_value(outport,en);					    // set enable bit
	_delay_ms(1);						            // wait 1 msecond
	clear_pin_value(outport,en);				    // clr enable bit
	
}
 
void LCDData(char dataout)				       		// send data to LCD
{
	set_port_value(outport,dataout);			    // output dataout on output port
	set_pin_value(outport,rs);			  	        // setbit rs=1 (send data)
	set_pin_value(outport,en);		   		        // set enable bit
	_delay_ms(1);						            // wait 1 msecond
	clear_pin_value(outport,en);					// clr enable bit
}

/*
 * the string must be ended with a null char
 */
void LCD_SendStr(char * ptr)				       // send string function
{
	int i=0;
	while(ptr[i]!='\0')
	{
		LCD_SendData(ptr[i]);

		i++;
	}
}

void LCD_Gotoxy(int x,int y)		  		 	 // LCD write data in specific position
{
	if(y>0)								   	 	 // it mean that i will write in second row
	{
		LCD_SendCmd(0xC0+x);					 // second row start @ address = 0xC0
	}
	else										 // i will write in first row
	{
		LCD_SendCmd(0x80+x);					 // first row start @ address = 0x80
	}
	_delay_ms(200);
}

void LCD_Clear()
{
	LCD_SendCmd(0x01);
	_delay_ms(200);
}
