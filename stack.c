
#define MaxStack 100
#include "stack.h"
#include<stdio.h>
#include<stdlib.h>

//Assistant Functions
stack_type calc(stack *s1, stack *s2, stack_type ch)
{
	int a=0,a1;
	char v1, v2, v3, tmp;
	a1=operator_grade(top(s2));
       printf("\nCurrent Solution:\n");
	while ((!( is_empty(s2))) && ( a1>a))//if higher and not empty
	{
		v1 = pop(s2);
		v2 = pop(s1);
		v3 = pop(s1);
		push(s1,ch--);
		printf("\nSolving: %c%c%c=%c\n", v3, v1, v2, top(s1));
		tmp=top(s2);
		a=operator_grade(tmp);
	}
	return ch;
}

int operator_grade(stack_type op)
{
	int a1=0;
	if(op == '^')
		a1=3;
    else if((op == '*') || (op == '/'))
		a1=2;
	else if((op == '+') || (op == '-'))
		a1=1;
	return a1;
}

stack *create_stack()
{
	stack *ps = (stack*)malloc(sizeof(stack));
	if(!ps)
	{
		printf("\nMemory allocation error\n");
		return 0;
	}
	ps->top = -1;
	return ps;
}

void push(stack *ps, stack_type value)
{
	if (is_full(ps))
	{
		printf("The stack is Full");
		return;
	}
	ps->top++;
	ps->arr[ps->top] = value;
}

char pop(stack *ps)
{
	char temp;
	if (is_empty(ps))
	{
		
		return -1;
	}
	temp = ps->arr[ps->top];
	ps->top--;
	return temp;
}

char top(stack *ps)
{
	if (is_empty(ps))
		return NULL;
	return ps->arr[ps->top];
}

int is_empty(stack *ps)
{
	return ps->top == -1;//return 1 (empty) else return 0
}

int is_full(stack *ps)
{
	return ps->top ==  (MaxStack-1); 
}

