
#ifndef poly_h
#define poly_h

typedef int list_type;

typedef struct node 
{
   list_type coeff;	
   list_type pow;
   struct node *next;
   struct node *prev;
}node;

typedef struct poly
{
	node *head;
	node *tail;
}poly;

//ASSISTANT FUNCTIONS

poly* build_list();
void init_list(poly *lst);
int isEmpty(poly *lst);
void order_pol(poly* polynom);
void insert_after(poly *lst, list_type value, list_type power, int idx);
void insert_last(poly *p3, list_type value, list_type power);
void insertFirst(poly *lst, list_type value, list_type power );
void print_poly(poly *polynom);//in ascending order of powers
node *mult_of(node *newnode, node *curr1, node *curr2);//bonus assistant function
void free_list(poly *polynom);
// EX 2 FUNCTIONS

poly *sum_of(poly *p1, poly *p2);//func num. 1

poly *diff_of(poly *p1, poly *p2);//func num. 2

poly *multipl(poly *polynom, int z);//func num. 3

int teta(poly *polynom);// func num. 4

void insert_new(poly *polynom ,list_type coefficient, list_type power);// func num. 5

poly *new_polynom(list_type value, list_type power);// func num. 6

void print_rever(poly *polynom);// func num. 7

poly *bonus(poly *p1, poly *p2);// func num. 8

#endif
