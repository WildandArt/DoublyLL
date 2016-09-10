#include <stdlib.h>
#include "poly.h"
#include<stdio.h>
#include<string.h>
//List of help functions
void init_list(poly *lst)
{
	lst->head = lst->tail = NULL;	
}

int isEmpty(poly *lst)
{
	return lst->head == NULL;
}

poly *build_list()
{
	poly *lst = (poly*)malloc(sizeof(poly));
	if (!lst){
		puts("Error by create new item!!");
		system("Pause");
		exit(1);
	}

	lst->head = lst->tail = NULL;

	return lst;
}

void insertFirst(poly *lst, list_type value, list_type power )
{
	//create a new link
	node *link = (node*)malloc(sizeof(node));
	if(!link)
	{
		puts("Error by create new item!!");
		system("Pause");
		exit(1);
	}
	link->coeff = value;
	link->pow = power;
	link->next = NULL;
	link->prev = NULL;
	
	if(isEmpty(lst))
	{
		//make head & tail pointing to link
		lst->head = lst->tail = link;	
	}
	else 
	{
		//update first prev link
		lst->head->prev = link;
		//point it to old first link
		link->next = lst->head;
		//point first to new first link
		lst->head = link;
	}
}

void insert_after(poly *lst, list_type value, list_type power, int idx)
{
	if (!isEmpty(lst))
	{
		int i;
		//start from the first link
		node* current = lst->head;
		node* newLink = NULL;

		//navigate through list
		for (i=0; i<idx && current != NULL ;i++)
			current = current->next;

		if (current == NULL)//if we got to the null before we got to the right indx
			printf("ERROR insert_after function, wrong index");
		if (current == lst->tail)
			insert_last(lst,value,power);
		//create a link
		newLink = (node*)malloc(sizeof(node));
		if(!newLink)
		{
		puts("Error by create new item!!");
		system("Pause");
		exit(1);
		}
		newLink->coeff = value;
		newLink->pow = power;
		//assign new link pointers
		newLink->prev = current;
		newLink->next = current->next;
		//chain current and current->next to new link
		current->next->prev = newLink;
		current->next = newLink;
	}
}

void insert_last(poly *p3, list_type value, list_type power)
{
	//create a new link
	node *link = (node*)malloc(sizeof(node));
	if(!link)
	{
		puts("Error by create new item!!");
		system("Pause");
		exit(1);
	}
	link->coeff = value;
	link->pow=power;
	link->next = NULL;
	link->prev = NULL;
	//we need to know if the list is empty
	if(p3->head==NULL)
		p3->head=p3->tail=link;
	else 
	{
		link->prev=p3->tail;
		//link->next= NULL//already
		p3->tail->next=link;
		p3->tail=link;
	}
}
//main functions
poly *sum_of(poly *p1, poly *p2)
{
	poly *p3=build_list();
	node *curr1=p1->head;
	node *curr2=p2->head;
	
	while((curr1) && (curr2))//until heads not NULL
	{
		if(curr1->pow==curr2->pow)
		{
			insert_last(p3, curr1->coeff+curr2->coeff, curr1->pow);
			curr1=curr1->next;
			curr2=curr2->next;
		}
		else if((curr1->pow) < (curr2->pow))
		{
			insert_last(p3, curr1->coeff, curr1->pow);
			curr1=curr1->next;
		}
		else //(curr1->pow > curr2->pow)
		{
			insert_last(p3,curr2->coeff, curr2->pow);
			curr2->next;
		}
	}
	while(curr1)
	{
		insert_last(p3, curr1->coeff, curr1->pow);
		curr1=curr1->next;
	}
	while(curr2)
	{
		insert_last(p3, curr2->coeff, curr2->pow);
		curr2=curr2->next;
	}
	return p3;
}

poly *diff_of(poly *p1, poly *p2)
{
	poly *p3=build_list();
	node *curr1=p1->head;
	node *curr2=p2->head;
	
	while(curr1 && curr2)//until heads not NULL
	{
		if(curr1->pow==curr2->pow)
		{
			insert_last(p3, curr1->coeff-curr2->coeff, curr1->pow);
			curr1=curr1->next;
			curr2=curr2->next;
		}
		else if((curr1->pow) < (curr2->pow))
		{
			insert_last(p3, curr1->coeff, curr1->pow);
			curr1=curr1->next;
		}
		else//(curr1->pow > curr2->pow)
		{
			insert_last(p3,-(curr2->coeff), curr2->pow);
			curr2->next;
		}
	}

	while(curr1)
	{
		insert_last(p3, curr1->coeff, curr1->pow);
		curr1=curr1->next;
	}
	while(curr2)
	{
		insert_last(p3, -(curr2->coeff), curr2->pow);
		curr2=curr2->next;
	}
	return p3;
}

poly *multipl(poly *polynom, int z)
{
	node *currm=NULL;
	currm=polynom->head;

	if(isEmpty(polynom))
	{
		printf("the list is empty, there's nothing to multiply");
		return;
	}
	while(currm!=NULL)
	{
		currm->coeff*=z;
		currm=currm->next;
	}	
	return polynom;
}

void seder_godel(poly *polynom)
{
	if(isEmpty)
	{
		printf("the list is empty");
		return;
	}
	else
	printf("\nthe seder godel is % d\n", polynom->tail->pow);
}

poly *new_polynom(list_type value, list_type power)
{
	poly *newpol=build_list();
	node *newmem;
	newmem=(node*)malloc(sizeof(node));
	if(!newmem)
	{
		printf("memory allocation failed");
		return;
	}
	newpol->head=newpol->tail=newmem;
	newmem->coeff=value;
	newmem->pow=power;
	newmem->next=NULL;
	newmem->prev=NULL;
	return newpol;
}

void order2_pol(poly* polynom)
{
	char response;
	node* temp;
	node* curr=NULL;//search for index
	int counter=0;
	printf("\nenter the new polynom\n");
	do
	{
	temp=(node*)malloc(sizeof(node));
	if(!temp)
	{
		printf("memory allocation failed");
		return;
	}
	temp->next=NULL;
	temp->prev=NULL;
	printf("enter the COEFFICIENT and the POWER of the polynom. \n");
	scanf("%d %d", &temp->coeff,&temp->pow);
	if(isEmpty(polynom))
	{
		curr=polynom->head=polynom->tail=temp;//insert the first element
		//curr=polynom->head;
	}
	else
	{
	 if(temp->pow > polynom->tail->pow)//if bigger than the last pow
		insert_last(polynom, temp->coeff, temp->pow);
	else if(temp->pow == polynom->tail->pow)
		polynom->tail->coeff+=temp->coeff;//dont insert but sum the coeffs of the same power
	else if(temp->pow < polynom->tail->pow)//smaller than the last pow
	{
		//we need to find the indx of the node that is smaller or equal to the new node
		while(curr->pow <= temp->pow)
		{
			curr=curr->next;
			counter++;
		}
			if(curr->pow==temp->pow)
				curr->coeff += temp->coeff;
				//insert_after(polynom, curr->coeff+temp->coeff, curr->pow, );
		else
		{
			if(counter==0)

				insertFirst(polynom, temp->coeff, temp->pow);
			else

				insert_after(polynom, temp->coeff,temp->pow, counter);//else insert at the index
		}
	}
	}
	 printf("\nDo you want to add another number? Say 'y' to continue, type enter to stop\n");
        getchar();
        response = getchar();
		counter=0;
	}
	while(response == 'y');
	//return;
}

void sortedInsert(poly *lst)
{
	int count = 0, index = 0;
	int ch = 'y';
	list_type coeff, power;

	printf("\n\n#Please enter value to build Equation:\n");
	while ((ch == 'y') || (ch == 'Y'))
	{

		printf("Input [coefficient #%d]: ", index + 1);
		scanf("%d", &coeff);
		printf("Input [Power #%d]: ", index + 1);
		scanf("%d", &power);

		index++;

		if (isEmpty(lst)) // empty list -> insert to first node.
		{
			insertFirst(lst, coeff, power);
		}
		else if (lst->head->prev == NULL) //when only one node exist in list.
		{
			if (power > lst->head->pow)
			{
				insert_last(lst, coeff, power);
			}
			else if (power < lst->head->pow)
			{
				insertFirst(lst, coeff, power);
			}
			else
			{
				lst->head->coeff += coeff;
			}
		}
		else if (lst->head->next != NULL)
		{

			{
				while (lst->head != NULL)
				{
					count++;

					if ((power < lst->head->next->pow) && (power > lst->head->pow)) //when there are more then one node.
					{
						insert_after(lst, coeff, power, count);
						break;
					}
					else if (power == lst->head->pow)
					{
						lst->head->coeff += coeff;
						break;
					}
					else
						lst->head->next;
				}
			}
		}

		printf("\nDo you want to Continue? \n");
		printf("For Yes Enter ----->[Y]\n");
		printf("For No Enter ------>[N]\n");
		printf("-------------------> ");
		ch = _getch();
		printf("\n\n");
	}
} 

void insert_new(poly *polynom ,list_type coefficient, list_type power)
{
	//adding a node in an ascending order
	//if the list is empty add_first
	//if node->pow > tail->pow; then add_last
	//if node->pow== tail->pow; then sum_of them
	//if node->pow < tail-> pow; then find the index of the smaller and insert after him. start from tail

}

void print_poly(poly *polynom)
{
	//1.--power==0, show only coeff
	//2.--no "+" before first element
	//3.--if coeff equals zero then DONT print it
	//4.--power 1, dont show the power
	//5.coeff 1,print without coeff
	node* curr2;
	curr2=(node*)malloc(sizeof(node));
	if(!curr2)
	{
		printf("memory allocation failed");
		return;
	}
	curr2->next=NULL;
	curr2->prev=NULL;
	curr2=polynom->head;

	while(curr2!=NULL)
	{
		if((curr2->coeff==0) && (curr2->prev==NULL))//first and zero
			printf("0");
		else if(curr2->coeff==0)
			printf("");
		else//coeff!=0
		{
			if(curr2->prev==NULL)//if first node
			{
				if(curr2->coeff>0)//positive coeff
				{
				if(curr2->pow==0)
				printf("%d",curr2->coeff);
				else if(curr2->pow==1)
				printf("%d*x",curr2->coeff);
				else if(curr2->coeff==1)
					printf("x^%d",curr2->pow);
				else
				printf("%d*x^%d",curr2->coeff, curr2->pow);
				}
				if(curr2->coeff<0)//negative coeff
				{
					if(curr2->pow==0)//print only coeff
				printf("%d",curr2->coeff);
				else if(curr2->pow==1)//print "coeff*x"
					if(curr2->coeff==-1)
						printf("-x");
					else
					printf("%d*x",curr2->coeff);
				else if(curr2->coeff==-1)//coeff is -1
					printf("-x^%d",curr2->pow);
				else
				printf(" %d*x^%d",curr2->coeff, curr2->pow);
				}
			}
			else//--------------NOT FIRST
			{
				if(curr2->coeff>0)//pos coeff
				{
				if(curr2->pow==0)//print only coeff
					printf("+ %d",curr2->coeff);
				else if(curr2->pow==1)//print "coeff*x"
					if(curr2->coeff==1)
						printf(" + x ");
						else printf(" + %d*x",curr2->coeff);
				else 
					printf("+ %d*x^%d",curr2->coeff, curr2->pow);
				}
				if(curr2->coeff<0)//neg coeff
				{
					if(curr2->pow==0)//print only coeff
						printf(" %d",curr2->coeff);
					else if(curr2->pow==1)//print "coeff*x"
						if(curr2->coeff==-1)
							printf(" -x ");
							else printf(" %d*x",curr2->coeff);
				else 
					printf(" %d*x^%d",curr2->coeff, curr2->pow);
				}
			}
		}
		curr2=curr2->next;
	}
}//while

void print_rever(poly *polynom)
{
	//1.--power==0, show only coeff
	//2.--no "+" before first element
	//3.--if coeff equals zero then DONT print it
	//4.--power 1, dont show the power
	//5.coeff 1,print without coeff
	node* curr2;
	curr2=(node*)malloc(sizeof(node));
	if(!curr2)
	{
		printf("memory allocation failed");
		return;
	}
	curr2->next=NULL;
	curr2->prev=NULL;
	curr2=polynom->tail;
	//curr2->coeff=polynom->head->coeff;
	//curr2->pow=polynom->head->pow;
	while(curr2!=NULL)
	{
		if((curr2->coeff==0) && (curr2->next==NULL))//last node and zero
			printf("0");
		else if(curr2->coeff==0)
			printf("");
		else//coeff!=0
		{
			if(curr2->next==NULL)//if last node
			{
				if(curr2->coeff>0)//positive coeff
				{
				if(curr2->pow==0)
				printf("%d",curr2->coeff);
				else if(curr2->pow==1)
				printf("%d*x",curr2->coeff);
				else if(curr2->coeff==1)
					printf("x^%d",curr2->pow);
				else
				printf("%d*x^%d",curr2->coeff, curr2->pow);
				}
				if(curr2->coeff<0)//negative coeff
				{
					if(curr2->pow==0)//print only coeff
				printf("%d",curr2->coeff);
				else if(curr2->pow==1)//print "coeff*x"
					if(curr2->coeff==-1)
						printf("-x");
					else
					printf("%d*x",curr2->coeff);
				else if(curr2->coeff==-1)//coeff is -1
					printf("-x^%d",curr2->pow);
				else
				printf(" %d*x^%d",curr2->coeff, curr2->pow);
				}
			}
			else//--------------NOT FIRST
			{
				if(curr2->coeff>0)//pos coeff
				{
				if(curr2->pow==0)//print only coeff
					printf("+ %d",curr2->coeff);
				else if(curr2->pow==1)//print "coeff*x"
					if(curr2->coeff==1)
						printf(" + x ");
						else printf(" + %d*x",curr2->coeff);
				else 
					printf("+ %d*x^%d",curr2->coeff, curr2->pow);
				}
				if(curr2->coeff<0)//neg coeff
				{
					if(curr2->pow==0)//print only coeff
						printf(" %d",curr2->coeff);
					else if(curr2->pow==1)//print "coeff*x"
						if(curr2->coeff==-1)
							printf(" -x ");
							else printf(" %d*x",curr2->coeff);
				else 
					printf(" %d*x^%d",curr2->coeff, curr2->pow);
				}
			}
		}
		curr2=curr2->prev;
	}
}//end of while


void main()
{
	//poly* p3;
	poly* p1=build_list();
	//poly* p2=build_list();
	//poly* p3=build_list();
	order2_pol(p1);
	
	print_poly(p1);
	printf("\n");
	print_rever(p1);
	/*order2_pol(p2);
	print_poly(p2);
	p3=sum_of(p1,p2);*/
	/*printf("\nThe Sum of two polynoms is:\n");
	print_poly(p3);*/
	system("pause");
}
