#include<stdio.h>
#include<stdlib.h>
struct double_linked_list
{
	int num;
	struct double_linked_list *next;
	struct double_linked_list *prev;
};
int c=0;
typedef struct double_linked_list node;
node *first=NULL;
node *last=NULL;
node *search(int num,int opt);
node *insert(int opt,int num,node *t);
void show(int opt);
void *del(int num);
int main()
{
	node *p;
	int num,choice,pos;
	while (1)
	{
		printf("\n1-Add a number \n2-Insert a number \n3-Delete a number \n4-Search \n5-Show \n6-Exit \nSelect an option: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter the number: ");
				scanf("%d",&num);
				p=insert(0,num,p);
				break;
			
			case 2:
				if (c==0)
					printf("Empty");
				else
				{
					printf("Enter the position(1-based index): ");
					scanf("%d",&num);
					if (num==1)
					{
						node *t=(node *)malloc(sizeof(node));
						t->next=first;
						t->prev=NULL;
						first->prev=t;
						first=t;
						printf("Enter the number to insert: ");
						scanf("%d",&t->num);
					}
					else if (num==c)
					{
						node *t=(node *)malloc(sizeof(node));
						last->next=t;
						t->num=last->num;
						printf("Enter the number: ");
						scanf("%d",&last->num);
						last->next=t;
						t->next=NULL;
						t->prev=last;
						last=t;
						p=last->next;
					}
					else if (num==c+1)
					{
						node *t=(node *)malloc(sizeof(node));
						last->next=t;
						printf("Enter the number: ");
						scanf("%d",&t->num);
						t->next=NULL;
						t->prev=last;
						last=t;
						p=last->next;
					}
					else if (num<c)
						p=insert(1,num,p);
					else
						printf("Invalid Postion\n");
				}
				break;
			
			case 3:
				printf("Enter the number: ");
				scanf("%d",&num);
				if (c==0)
					printf("Empty");
				else if (c==1)
				{
					if (num!=first->num)
						printf("Invalid Number\n");
					else
					{
						c--;
						first=last=p=NULL;
						c=0;
					}
					
				}
				else
				{
					if (first->num==num)
					{
						first->next->prev=NULL;
						first=first->next;
						c--;
					}
					else if (last->num==num)
					{
						last->prev->next=NULL;
						last=last->prev;
						p=last;
						c--;
					}
					else
					{
						del(num);
					}
				}
				break;
			
			case 4:
				if (c==0)
					printf("Empty");
				else
				{
				printf("Enter the number to search: ");
				scanf("%d",&num);
				search(num,1);
				}
				break;
			
			case 5:
				if (c==0)
					printf("Empty");
				else
				{
				printf("1-Assending Order \n2-Desending Order \nSelect an option: ");
				scanf("%d",&num);
				show(num);
				}
				break;
				
			case 6:
				exit(0);
				
			default:
				printf("Invalid Option\n");
		}
	}
	return 1;
}
node *insert(int opt,int num,node *t)
{
	if (opt==0)
	{
		t=(node *)malloc(sizeof(node));
		if (first==NULL)
		{
			first=last=t;
			t->num=num;
			t->next=t->prev=NULL;
		}
		else
		{
			t->prev=last;
			last->next=t;
			last=t;
			last->num=num;
			last->next=NULL;
		}
	}
	else
	{
		node *m=(node *)malloc(sizeof(node));
		node *p=first;
		int count=0;
		while (count!=num-1)
		{
			p=p->next;
			count++;
		}
		m->num=p->num;
		printf("Enter a number: ");
		scanf("%d",&p->num);
		p->next->prev=m;
		m->next=p->next;
		p->next=m;
		m->prev=p;	
	}
	c++;
	return last->next;
}
void show(int opt)
{
	node *t;
	if (opt==1)
	{
		for (t=first;t!=NULL;t=t->next)
			printf("->%d",t->num);
	}
	else
	{
		for (t=last;t!=NULL;t=t->prev)
			printf("->%d",t->num);
	}
	printf("\n");
}
node *search(int num,int opt)
{
	int prc=0,count=1;
	node *t=first;
	for (t=first;t!=NULL;t=t->next,count++)
		if (t->num==num)
		{
			prc=1;
			if (opt==1)
			{
				printf("Found the number at %d position\n",count);
				break;
			}
			else
				return t;
		}
	if (prc==0 && opt==1)
		printf("\nNumber not found\n");
	else
		return NULL;
}
void *del(int num)
{
	node *p;
	p=search(num,2);
	if (p==NULL)
		printf("Invalid Number");
	else
	{
		p->prev->next=p->next;
		p->next->prev=p->prev;
	}
	c--;
}
