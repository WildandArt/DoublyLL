#define MaxStack 100
#ifndef stack_h
#define stack_h

typedef char stack_type;

typedef struct stack
{
	stack_type arr[MaxStack];
	int top;
}stack;
//Assistant Functions
int operator_grade(stack_type op);
stack_type calc(stack *s1,stack *s2,stack_type ch);
stack *create_stack();
void push(stack *, char);
char pop(stack *);
char top(stack *);
int is_empty(stack *s);
int is_full(stack *);
#endif