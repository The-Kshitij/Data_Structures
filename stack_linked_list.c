#include<stdio.h>
#include<stdlib.h>
int c=0;
struct stack
{
	int num;
	struct stack *next;
};
typedef struct stack node;
node *first=NULL;
node *last=NULL;
void add(int num);
void show();
void del();
void search(int num);
int main()
{
	int num,choice;
	while (1)
	{
		printf("\n1-Append \n2-Delete \n3-Search \n4-Show \n5-Exit \nSelect an option: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter the number: ");
				scanf("%d",&num);
				add(num);
				break;
				
			case 2:
				if (c==0)
					printf("Empty\n");
				else
				{
					if (c==1)
					{
						printf("Deleted");
						first=last=NULL;
					}
					else
						del();
					c--;
				}
				break;
				
			case 3:
				if (c==0)
					printf("Emty\n");
				else
				{
					printf("Enter a number to search: ");
					scanf("%d",&num);
					search(num);
				}
				break;
				
			case 4:
				if (c==0)
					printf("Empty");
				else
					show();
				break;
				
			case 5:
				exit(0);
				
			default:
				printf("Invalid Option\n");
		}
	}
	return 1;
}
void add(num)
{
	node *t=(node *)malloc(sizeof(node));
	t->next=NULL;
	t->num=num;
	if (first==NULL)
		first=last=t;
	else
	{
		last->next=t;
		last=t;
	}
	c++;
}
void show()
{
	node *t=first;
	while (t!=NULL)
	{
		printf("->%d",t->num);
		t=t->next;
	}
	printf("\n");
}
void del()
{
	node *t;
	for (t=first;t->next!=last;t=t->next)
		;
	t->next=NULL;
	last=t;
}
void search(int num)
{
	node *t;
	int count=1,prc=0;
	for (t=first;t!=NULL;t=t->next,count++)
	{
		if (t->num==num)
		{
			prc=1;
			printf("Found at %d position\n",count);
			break;
		}
	}
	if (prc==0)
		printf("Number not found\n");
}
