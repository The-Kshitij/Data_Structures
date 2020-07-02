#include<stdio.h>
#include<stdlib.h>
struct double_circular_linked_list
{
	int num;
	struct double_circular_linked_list *next;
	struct double_circular_linked_list *prev;
};
int c=1;
typedef struct double_circular_linked_list node;
node *first=NULL;
node *last=NULL;
void insert(int opt,int num);
void show();
void search(int num);
void del(int num);
int main()
{
	int choice,num;
	node *p=NULL;
	while (1)
	{
		printf("\n1-Add new element \n2-Insert \n3-Delete \n4-Search \n5-Show \n6-Exit\nSelect an option: ");
		scanf("%d",&choice);
			
		switch (choice)
		{
			case 1:
				printf("Enter the number: ");
				scanf("%d",&num);
				insert(0,num);
				c++;
				break;
					
			case 2:
				if (c==1)
				{
					printf("Enter the number: ");
					scanf("%d",&num);
					insert(0,num);
					c++;
				}
				else
				{
				printf("Enter the position: ");
				scanf("%d",&num);
				if (num==1)
				{
					node *t=(node *)malloc(sizeof(node));
					t->next=first->next;
					first->next->prev=t;
					first->next=t;
					t->prev=first;
					t->num=first->num;
					printf("Enter the number: ");
					scanf("%d",&first->num);
					c++;
				}
				else if (num==c)
				{
					node *t=(node *)malloc(sizeof(node));
					last->next=t;
					t->next=first;
					t->prev=last;
					last=t;
					first->prev=last;
					printf("Enter the number: ");
					scanf("%d",&t->num);
					c++;
				}
				else if(num<c)
				{
					insert(1,num);
					c++;
				}
				else
					printf("Invalid Number\n");
				}
				break;
					
			case 3:
				if (c==1)
					printf("Empty");
				else
				{
				printf("Enter the number to delete: ");
				scanf("%d",&num);
				if (c==2)
				{
					if (num==first->num || num==last->num)
					{
						printf("Deleted\n");
						c--;
						first=last=NULL;
					}
					else
						printf("Invalid Number");
				}
				else
				{
				if (first->num==num)
			 	{
			 		last->next=first->next;
			 		first->next->prev=last;
			 		first=first->next;
			 		c--;
				}
				else if (last->num==num)
				{
					first->prev=last->prev;
					last->prev->next=first;
					last=last->prev;
					c--;
				}
				else
					del(num);
				}
				}
				break;
					
			 case 4:
			 	if (c==1)
			 		printf("Empyty\n");
			 	else
			 	{
				printf("Enter the number to search: ");
			 	scanf("%d",&num);
			 	search(num);
			 	}
			 	break;
				
			case 5:
				if (c==1)
					printf("Empty\n");
				else
					show();
				break;
					
			case 6:
				exit(0);
					
			default:
				printf("Invalid Choice\n");
		}
	}
	return 1;
}
void insert(int opt,int num)
{
	node *t=(node *)malloc(sizeof(node));
	if (opt==0)
	{
		t->num=num;
		if (first==NULL)
		{
			c=1;
			first=last=t;
			t->next=first;
			t->prev=last;
		}
		else
		{
			last->next=t;
			t->next=first;
			t->prev=last;
			last=t;
			first->prev=last;
		}
	}
	else
	{
		int count=0;
		node *p=first;
		while (count!=c)
		{
			p=p->next;
			count++;
		}
		node *m=first;
		while (m->next!=p)
			m-m->next;
		t->num=p->num;
		t->next=p;
		p->prev=t;
		m->next=t;
		t->prev=m;
		printf("Enter the number: ");
		scanf("%d",&p->num);
	}
}
void show()
{
	int choice;
	printf("1-Assending Order\n2-Desending Order\nSelect a way for traversal: ");
	scanf("%d",&choice);
	if (choice==1)
	{
		node *t=first->next;
		printf("->%d",first->num);
		while (t!=first)
		{
			printf("->%d",t->num);
			t=t->next;
		}
	}
	else
	{
		node *t=last->prev;
		printf("->%d",last->num);
		while (t!=last)
		{
			printf("->%d",t->num);
			t=t->prev;
		}
	}
	printf("\n");
}
void search(int num)
{
	int prc=0;
	int count=2;
	if (first->num==num)
	{
		printf("Found at position 1\n");
		prc=1;
	}
	else
	{
		node *t;
		for (t=first->next;t!=first;t=t->next,count++)
			if (t->num==num)
			{
				prc=1;
				printf("Found at position %d\n",count);
				break;
			}
	}
	if (prc==0)
		printf("Number not found\n");
}
void del(int num)
{
	node *t=first->next;
	int prc=0;
	while (t!=first)
	{
		if (t->num==num)
		{
			prc=1;
			break;
		}
		t=t->next;
	}
	if (prc==1)
	{
		t->prev->next=t->next;
		t->next->prev=t->prev;
		c--;
	}
	else
		printf("Number not found\n");
}
