// name: Artemy Ozerski
// ID: 321018665
//group 61104
#include <stdlib.h>
#include "poly.h"
#include "stack.h"
#include<stdio.h>
#include<string.h>

void exA();
void ex1();
void ex2();
void ex3();
void ex4();
void ex5();
void ex6();
void ex7();
void ex8();

void main()
{
	int select1 = -1;
	int select2 =-1;

	while (select1)
	{
		printf("For exercise 1--->Press 1\n");
		printf("For exercise 2--->Press 2\n");
		printf("For Exit Press 0\n");
			printf("\n\nPlease choose the exercise 1 or 2, or Press 0 to exit\n");
			scanf("%d", &select1);
			select2 =-1;
		switch (select1)
		{
		case(0): 
			{
		    printf("EXITED\n");
				break;
			}
		case (1):
			{
			while (select2)
				  {
					switch (select2)
					{
					case (1): exA();  break;
					case (0): break;
					}
			      printf("Press 0 to return\n\n");
			      printf("\nPlease choose the exercise 1 or 0 to exit\n");
				  scanf("%d", &select2);
			   	  flushall(); 
		     }
		  }
		case (2):
		{
			while (select2)
			{
				switch (select2)
				{
					case (1): ex1();
						break;  
					case (2): ex2();
						break;  
					case (3): ex3();
						break;
					case (4): ex4();
						break;
					case (5): ex5();
						break;
					case (6): ex6();
						break;
					case (7): ex7();
						break;
					case (8): ex8();
						  break;
					case (0): break;
				}
				printf(" ---1--->Sum of two Polynomials\n");
				printf(" ---2--->Difference of two Polynomials\n");
				printf(" ---3--->Multiplication of Polynomials and a constant\n");
				printf(" ---4--->Estimate the Teta of the polynomial\n");
				printf(" ---5--->Insert new member into the polynomial\n");
				printf(" ---6--->Create new Polynomial with one member\n");
				printf(" ---7--->Print the Polynomial in Descending order of Powers\n");
				printf(" ---8--->(Bonus)Multiplication of two Polynomials\n");
				printf("To Return Press 0\n\n");
				printf("\nChoose the number of exercise(1-8) or 0 to exit\n");
					scanf("%d", &select2);
				}
			}
     	}
	}
}
//--------------------------------Exercise 1-----------------------------------------------------

void exA()
{
	int i, a1=0, a2=0;
	char op, op_prev, ch='Z';
	stack *s1 = create_stack();
	stack *s2 = create_stack();
	char *str;
	str=(char*)malloc(100*sizeof(char));
		if(!str)
		{
			printf("\nMemory allocation failed\n");
			return;
		}
	printf("Type in your equation, You may use only operands:A-H or 0-9 and only operators: *,-,+,^,/;\n");
	gets(str);

	for (i=0; i < strlen(str); i++)
	{
		op = *(str + i);
		if ((!(((op <= 'H') && ('A' <= op))||(('0' <= op) && (op <= '9')))) && (!((op == '*') || (op == '^') || (op == '/') || (op == '+') || (op == '-') || (op == ' '))))
		{
			printf("Invalid Input, Please type only valid operators/operands\n");
			return;
		}
	}
	for (i = 0; i < strlen(str); i++)
	{
		op = *(str + (i));
		if(op == ' ')
		{    
			while(op == ' ')
			{
			op = *(str + (++i));
			}
		}
		if ((('A' <= op) && (op <= 'H')) || (('0' <= op) && (op <= '9')))
			push(s1, op);
		if ((op == '+') || (op == '-') || (op == '*') || (op == '/') || (op == '^'))
		{
			a1=operator_grade(op);

			op_prev = top(s2);

			if (op_prev)
			a2=operator_grade(op_prev);

			if ( is_empty(s2) || (a1 > a2))
				push(s2, op);

			if (a2 >= a1)
			{
				ch=calc(s1,s2,ch);
				push(s2, op);
			}
		}
	}
	ch=calc(s1,s2,ch);
	printf("The Final Solution is:%c\n", top(s1));
	free(s1);
	free(s2);
	free(str);
}

//--------------------------------Exercise 2-----------------------------------------------------
void ex1()
{
	poly *p3;
	poly* p1=build_list();
	poly* p2=build_list();
	order_pol(p1);
	printf("\nFirst equation:\n");
	print_poly(p1);
	order_pol(p2);
	printf("\nSecond equation:\n");
	print_poly(p2);
	p3=sum_of(p1, p2);
	printf("\nSum Result:\n");
	print_poly(p3);
	free_list(p1);
	free_list(p2);
	free_list(p3);
	printf("\n\n");
}
void ex2()
{
	poly *p3;
	poly* p1=build_list();
	poly* p2=build_list();
	order_pol(p1);
	printf("\nFirst equation:\n");
	print_poly(p1);
	order_pol(p2);
	printf("\nSecond equation:\n");
	print_poly(p2);
	p3=diff_of(p1, p2);
	printf("\nDifference Result:\n");
	print_poly(p3);
	free_list(p1);
	free_list(p2);
	free_list(p3);
	printf("\n\n");
}
void ex3()
{
	int z;
	poly *p3;
	poly* p1=build_list();
	order_pol(p1);
	print_poly(p1);
	printf("\nEnter the Constant to multiply the polynomial\n");
	scanf("%d", &z);
	p3=multipl(p1, z);
	print_poly(p3);
	printf("\n\n");
	free_list(p1);
	free_list(p3);
}
void ex4()
{
	int res;
	poly* p1=build_list();
	order_pol(p1);
	print_poly(p1);
	res=teta(p1);
	printf("The result is: [%d]\n\n", res);
	printf("\n\n");
	free_list(p1);
}
void ex5()
{
	int c, p;
	poly* p1=build_list();
	order_pol(p1);
	print_poly(p1);
	printf("\nenter the Coefficient of the new member\n");
	scanf("%d", &c);
	printf("\nenter the Power of the new member\n");
	scanf("%d", &p);
	insert_new(p1, c, p);
	printf("\n After insertion:\n");
	print_poly(p1);
	printf("\n\n");
	free_list(p1);
}
void ex6()
{
	int c, p;
	poly *p3;
	printf("\nenter the Coefficient of the first list member\n");
	scanf("%d", &c);
	printf("\nenter the Power of the first list member\n");
	scanf("%d", &p);
	p3=new_polynom(c, p);
	printf("\nthe new list with one member:\n");
	print_poly(p3);
	printf("\n\n");
	free_list(p3);
}
void ex7()
{
	poly* p1=build_list();
	order_pol(p1);
	printf("\nThe function prints all the members of the polynom in Descending Power Order:\n");
	print_rever(p1);
	printf("\n\n");
	free_list(p1);
}
void ex8()
{
	poly* p1=build_list();
	poly* p2=build_list();
	poly *p3;
	order_pol(p1);
	print_poly(p1);
	order_pol(p2);
	printf("\nFirst Equation\n");
	print_poly(p1);
	printf("\nSecond Equation:\n");
	print_poly(p2);
	p3=bonus(p1,p2);
	printf("\nThe result is:\n");
	print_poly(p3);
	free_list(p1);
	free_list(p2);
	free_list(p3);
}


