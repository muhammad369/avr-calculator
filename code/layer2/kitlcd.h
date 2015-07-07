/*						register sent @ initialization of LCD 

			RS	RW	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0			DL: data length 1:8bit   0:4bit
	   	
			0	 0	 0	 0	 1	DL	 N	 F	 - 	 -			N: number of lines 1:2lines     0:1 line
															F: fonts   1:5x10     0:5x7
*/
#include<avr/io.h>
#include<util/delay.h>

/*************************** # define macros ****************************************/

#define rs 0 							// rs connected on pin 0 on PORTB
#define en 2							// enable connected on pin 2 on PORTB
#define outport 'B'						// determine the output port

/*************************** functions prototype ************************************/
 
void LCD_init();
void LCDCmd(char);						// divide command into 2 parts each part 4bit and send it
void LCDData(char);						// divide data into 2 parts each part is 4bit and send it
void LCD_SendCmd(char);					// send command to screen
void LCD_SendData(char);				// send character on screen
void LCD_SendStr(char * ptr);			// send string on screen
void LCD_Gotoxy(int x,int y);
void LCD_Clear();
