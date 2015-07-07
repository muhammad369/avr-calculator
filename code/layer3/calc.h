/*
 * calc.h
 *
 *      Author: Ali
 */
#include "stack.h"


#ifndef CALC_H_
#define CALC_H_




/*
 * returns the digit of given char, or -1 if no match
 */
int getDigit(char);

/*
 * returns a number representing the op, or -1 for no match
 */
int getOperator(char);



//char* long_toString(stack_ref ,long value);
//char* int_toString(int value);
#endif /* CALC_H_ */
