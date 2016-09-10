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
//void build_list(poly *newlist);
poly* build_list();
void init_list(poly *lst);
int isEmpty(poly *lst);
int length(poly *lst);
void order_pol(poly* polynom);
void order2_pol(poly* polynom);
void sortedInsert(poly *lst);
void insert_after(poly *lst, list_type value, list_type power, int idx);
void insert_last(poly *p3, list_type value, list_type power);
void insertFirst(poly *lst, list_type value, list_type power );
poly *sum_of(poly *p1, poly *p2);//func num. 1
poly *diff_of(poly *p1, poly *p2);//func num. 2
poly *multipl(poly *polynom, int z);//func num. 3
void seder_godel(poly *polynom);// func num. 4
poly *new_polynom(list_type value, list_type power);// func num. 5
void print_poly(poly *polynom);//regular print
void print_rever(poly *polynom);
