/*************** include important librabry ************************************/
#include <avr/io.h>
#include <util/delay.h>
#include "../layer1/DIO.h"

/********************************** define keys**********************************/
/*** ROW 0****/
#define r0c0 '7'						//			col0	col1	col2	col3
#define r0c1 '8'						//
#define r0c2 '9'						//
#define r0c3 '/'						// row0		  7		  8		  9		  /
/*** ROW 1****/							//
#define r1c0 '4'						//
#define r1c1 '5'						// row1		  4		  5		  6		  X
#define r1c2 '6'						//
#define r1c3 'X'						//
/*** ROW 2****/							// row2		  1		  2       3       -
#define r2c0 '1'						//
#define r2c1 '2'						//
#define r2c2 '3'						// row3      C/ON 	  0		  =		  +
#define r2c3 '-'						//
/*** ROW 3****/							//
#define r3c0 'C'						//
#define r3c1 '0'						//			     4 X 4 Keypad
#define r3c2 '='						//
#define r3c3 '+'						//
/****** start & end **/					//****************************************	
#define start 0							// 0 if first row0(first row) connected in pin0  && 4 if row0 connected in pin4 
#define end 4							// 4 if row3(last row) connected in pin4 && 8 if row3 connected in pin7
#define first 0							// pin0 if first row connected in pin0  or pin4 if first row connected in pin4
#define second 1						// pin1  or pin5	
#define third 2							// pin2  or pin6
#define fourth 3						// pin3  or pin7
#define out1 0xE0						// E0 or 0E        if columns connected on pin0-->pin3 choose 0E 
#define out2 0xD0						// D0 or 0D		   if columns connected on pin4-->pin7 choose D0
#define out3 0xB0						// B0 or 0B
#define out4 0x70						// 70 or 07 
#define comp 0xF0						// F0 or 0F		   F0 if columns->pin0 to pin3 && 0F if columns--> pin4 to pin7

/*input & output Port*/
#define OI 'C'

/************************** function prototype ********************************/

void keypad_init();						// initial function for keypad
char keypad_scan();						// get the character pressed on keypad

