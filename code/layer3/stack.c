/*
 * stack.c
 *
 *      Author: Ali
 */

#include "stack.h"



stack_ref new_stack(int max)
{
	stack_ref s=(stack_ref)malloc(sizeof(stack));
	s->max = max;
	s->p = 0;
	s->arr=(int*)malloc(max*sizeof(int));
	return s;
}

char stack_isfull(stack_ref s)
{
	if(s->p == s->max)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char stack_isempty(stack_ref s)
{
	if(s->p==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void stack_push (stack_ref s,int data)
{
	if (! stack_isfull(s))
	{
		s->arr[s->p]=data;
		s->p++;
	}
	else
	{

	}
}

int stack_pop (stack_ref s)
{
	if(! stack_isempty(s))
	{
		s->p--;
		return (s->arr[s->p]);
	}
	else
	{
		return 0;//error
	}
}

void stack_Clear(stack_ref s)
{
	s->p=0;
}

//char* stack_toString(stack_ref s)
//{
//	char* ptr=(char*)malloc((s->p+1) * sizeof(char) );//has to be deallocated
//	int i=0;
//	for( ; i <s->p; i++)
//	{
//		ptr[i] = s->arr[i];
//	}
//	ptr[i]='\0';
//	return ptr;
//}

void stack_free(stack_ref s)
{
	free(s->arr);
	free(s);
}

long get_value_of_stack(stack_ref s)
{
	long value=0;
	char weight=1;
	while(!stack_isempty(s))
	{
		value += stack_pop(s) * weight;
		weight *= 10;
	}
	return value;
}
