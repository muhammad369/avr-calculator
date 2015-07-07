/*
 * calc.c
 *
 *      Author: Ali
 */

#include "calc.h"
#include "stack.h"


char digits[10] = "0123456789";
char operators[4] = "+-X/";

int getDigit(char input)
{
	for(int i=9; i>=0; i--)
	{
		if(input == digits[i])
		{
			return i;
		}
	}
	//for loop ended with no match
	return -1;
}

int getOperator(char op)
{
	for(int i=3; i>=0; i--)
	{
		if(op == operators[i])
		{
			return i;
		}
	}
	//for loop ended with no match
	return -1;
}



//char* long_toString(stack_ref s,long value)
//{
//
//	long v = value;
//	int r=0;
//	do
//	{
//		r = v % 10;
//		stack_push(s, r);
//		v /= 10;
//	}
//	while(v != 0 || r != 0);
//
//	return stack_toString(s);
//}



//char* int_toString(int value)
//{
//	char s[size+1];
//	int v = value;
//	int r=0;
//
//	for(int i=0; i<size; i++)
//	{
//		r = v % 10;
//		s[i]=digits[i];
//		v /= 10;
//	}
//	s[3] = '\0';
//
//	return s;
//}
//
