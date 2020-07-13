#include<stdio.h>
#include<stdlib.h>
struct circular_linked_list
{
	int num;
	struct circular_linked_list *next;
};
int c=0;
typedef struct circular_linked_list node;
node *first=NULL;
node *last=NULL;
node *insert(int opt,int num,node *t);
node *search(int num);
void del(int num);
void show();
int main()
{
	node *p=NULL;
	int choice,num;
	
	while (1)
	{
		printf("\n1-Add a number \n2-Insert a number \n3-Delete a number \n4-Search \n5-Show \n6-Exit\nSelect your choice: ");
		scanf("%d",&choice);
		
		switch (choice)
		{
			case 1:
				printf("Enter the number to add to the list: ");
				scanf("%d",&num);
				p=insert(0,num,p);
				break;
				
			case 2:
				printf("Enter the position at which you want to insert %d: ",c);
				scanf("%d",&num);
				if (num==1)
				{
					node *t=(node *)malloc(sizeof(node));
					printf("Enter a number to insert: ");
					scanf("%d",&t->num);
					t->next=first;
					first=t;
					last->next=t;
					c++;
				}
				else if (num==c)
				{
					node *t=(node *)malloc(sizeof(node));
					t->num=last->num;
					last->next=t;
					printf("Enter a number to insert: ");
					scanf("%d",&last->num);
					last=t;
					last->next=first;
					c++;
				}
				else if (num==c+1)
				{
					node *t=(node *)malloc(sizeof(node));
					t->next=first;
					last->next=t;
					last=t;
					printf("Enter a number to insert: ");
					scanf("%d",&last->num);
					c++;
				}
				else if (num<c)
					p=insert(1,num,p);
				else
					printf("Invalid Position\n");
				break;
				
			case 3:
				printf("Enter the number to delete: ");
				scanf("%d",&num);
				if (c==1)
				{
					if (first->num==num || last->num==num)
					{
						printf("Deleted\n");
						c=0;
						first=NULL;
						last=NULL;
					}
					else
						printf("Invalid Number");
				}
				else if (c>1)
				{
				if (first->num==num)
				{
					first=first->next;
					last->next=first;
					c--;
				}
				else if (last->num==num)	
				{
					node *t;
					for (t=first;t->next!=last;t=t->next)
						;
					t->next=first;
					last=t;
					c--;
				}
				else
					del(num);
				}
				break;
				
			case 4:
				printf("Enter the number to search: ");
				scanf("%d",&num);
				if (first->num==num)
					printf("Found at position 1\n");
				else
					search(num);
				break;
			
			case 5:
				show();
				break;
			
			case 6:
				exit(1);
				
			default:
				printf("\nInvalid Choice\n");
		}
	}
}
node *insert(int opt,int num,node *t)
{
	c++;
	t=(node *)malloc(sizeof(node));
	if (opt==0)
	{
		t->num=num;
		if (first==NULL)
			first=last=t;
		else
		{
			last->next=t;
			last=t;
		}
		last->next=first;
	}
	else
	{
		node *p=first;
		int count=0;
		while (count!=c)
		{
			p=p->next;
			count++;
		}
		t->next=p->next;
		p->next=t;
		t->num=p->num;
		printf("Enter a number to insert: ");
		scanf("%d",&p->num);
	}
	return NULL;
}
void show()
{
	node *t=first->next;
	printf("->%d",first->num);
	while (t!=first)
	{
		printf("->%d",t->num);
		t=t->next;
	}
	printf("\n");
}
node *search(int num)
{
	node *t=first->next;
	int prc=0,count=2;
	while (t!=first)
	{
		if (t->num==num)
		{
			prc=1;
			printf("Fount at %d position",count);
			break;
		}
		t=t->next;
		count++;
	}
	if (prc==0)
	{
		printf("Number Not Found");
	}
}
void del(int num)
{
	node *p;
	node *t=first->next;
	int prc=0;
	while (t!=last)
	{
		if (t->num==num)
		{
			prc=1;
			c--;
			break;
		}
		else
			t=t->next;
	}
	if (prc==0)
		printf("Number not found");
	else
	{
		p=first;
		while (p->next!=t)
			p=p->next;
		p->next=t->next;
	}
}
