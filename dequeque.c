#include<stdio.h>
#include<stdlib.h>
int c=0;
struct dequeue
{
	int num;
	struct dequeue *next;
};
typedef struct dequeue node;
node *first=NULL;
node *last=NULL;
void search(int num);
void add(int opt,int num);
void show();
void del(int c2);
int main()
{
	int choice,num,c2;
	
	while (1)
	{
		printf("1-Append \n2-Delete \n3-Search \n4-Show \n5-Exit \nSelect an option: ");
		scanf("%d",&choice);
		
		switch (choice)
		{
			case 1:
				printf("1-Append at the starting \n2-Append at the end\nSelect an option: ");
				scanf("%d",&c2);
				printf("Enter the number: ");
				scanf("%d",&num);
				add(c2,num);
				c++;
				break;
			
			case 2:
				if (c==1)
				{
					printf("Deleted\n");
					first=last=NULL;
					c--;
				}
				else if (c!=0)
				{
					printf("1-Delete from the starting \n2-Delete from the end\nSelect an option: ");
					scanf("%d",&c2);
					del(c2);
				}
				else
					printf("Empty");
				break;
				
			case 3:
				printf("Enter the number to search: ");
				scanf("%d",&num);
				search(num);
				break;
				
			case 4:
				if (c==0)
					printf("Empty\n");
				else
					show();
				break;
				
			case 5:
				exit(0);
				
			default:
				printf("Invalid Choice\n");
		}
	}
	return 1;
}
void add(int opt,int num)
{
	node *t=(node *)malloc(sizeof(node));
	t->num=num;
	if (opt==1)
	{
		if (first==NULL)
		{
			first=last=t;
			last->next=NULL;
		}
		else
		{
			t->next=first;
			first=t;
		}
	}
	else if (opt==2)
	{
		if (first==NULL)
		{
			first=last=t;
			last=t;
			t->next=NULL;
		}
		else
		{
			last->next=t;
			last=t;
			t->next=NULL;
		}
	}
}
void show()
{
	node *t;
	for (t=first;t!=NULL;t=t->next)
		printf("->%d",t->num);
	printf("\n");
}
void del(int c2)
{
	if (c2==1)
		first=first->next;
	else
	{
		node *t;
		for (t=first;t->next!=last;t=t->next)
			;
		t->next=NULL;
		last=t;
	}
	c--;
	printf("Deleted\n");
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
			printf("Number found at position %d\n",count);
			break;
		}
	}
	if (prc==0)
		printf("Number not found\n");
}
