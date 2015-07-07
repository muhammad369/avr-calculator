/*
 * stack.h
 *
 *      Author: Ali
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdlib.h>


typedef struct{
	int max;
	int p; //p points to the next free place we can put in, not the last element
	int *arr;
}
stack;

typedef stack* stack_ref;

stack_ref new_stack(int max);
char stack_isfull(stack_ref s);
char stack_isempty(stack_ref s);
void stack_push (stack_ref s,int data);
int stack_pop (stack_ref s);
void stack_Clear(stack_ref s);
//char* stack_toString(stack_ref s);
void stack_free(stack_ref);
long get_value_of_stack(stack_ref );
#endif /* STACK_H_ */
