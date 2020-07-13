#include<stdlib.h>
#include<stdio.h>
struct queue
{
	int num;
	struct queue *next;
};
typedef struct queue node;
node *first=NULL;
node *last=NULL;
int c=0;
node *insert(node *t);
void show();
void del();
void search();
int main()
{
	int choice;
	node *p;
	while (1)
	{
		printf("\n1-Insert \n2-Delete \n3-Search \n4-Show \n5-Exit \nSelect your choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				p=insert(p);
				break;
				
			case 2:
				if (c==0)
					printf("!!Empty!!\n");
				else
					del();
				break;
			
			case 3:
				if (c==0)
					printf("!!Empty!!\n");
				else
					search();
				break;
				
			case 4:
				if (c==0)
					printf("!!Empty!!\n");
				else
					show();
				break;
					
			case 5:
				exit(0);
			
			default:
				printf("!!Invalid Option!!\n");
		}
	}
	return 1;
}
node *insert(node *t)
{
	t=(node *)malloc(sizeof(node));
	printf("Enter the number: ");
	scanf("%d",&t->num);
	if (c==0)
	{
		first=last=t;
		last->next=NULL;
	}
	else
	{
		last->next=t;
		last=t;
		last->next=NULL;
	}
	c++;
	return last;
}
void show()
{
	node *t;
	for (t=first;t!=NULL;t=t->next)
		printf("%d ",t->num);
	printf("\n");
}
void del()
{
	if (c==1)
		first=last=NULL;
	else
		first=first->next;
	c--;
}
void search()
{
	int n,k=0,process=0;
	printf("Enter the number: ");
	scanf("%d",&n);
	node *t;
	for (t=first;t!=NULL;t=t->next,k++)
		if (t->num==n)
		{
			printf("Found at %d position\n",k);
			process=1;
			break;
		}
	if (process==0)
		printf("!!Number Not Found!!");
}
