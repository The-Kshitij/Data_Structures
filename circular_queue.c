#include<stdio.h>
#include<stdlib.h>
struct circular_queue
{
	int num;
	struct circular_queue *next;
};
typedef struct circular_queue node;
int count=0;
node *first=NULL;
node *last=NULL;
node *insert(int num);
node *del();
void show();
int main()
{
	int choice,num;
	while (1)
	{
		printf("1-Add 2-Del 3-Show \n4-Exit\nSelect an option: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("Enter the number: ");
				scanf("%d",&num);
				insert(num);
				count++;
				break;
			
			case 2:
				if (count==0)
					printf("Empty\n");
				else
				{
					printf("Deleted\n");
					if (count==1)
						first=last=NULL;
					else
						del();
					count--;
				}
				break;
				
			case 3:
				if (count==0)
					printf("Empty\n");
				else
					show();
				break;
				
			case 4:
				exit(0);

			default:
				printf("Invalid Choice\n");
		}
	}
	return 0;
}
node *insert(int num)
{
	node *p=(node *)malloc(sizeof(node));
	p->num=num;
	if (first==NULL)
	{
		first=last=p;
	}
	else
	{
		last->next=p;
		last=p;
	}
	last->next=first;
}
node *del()
{
	node *t=first;
	while (t->next!=last)
		t=t->next;
	t->next=first;
	last=t;
}
void show()
{
	node *t=first;
	while (t->next!=first)
	{
		printf("->%d",t->num);
		t=t->next;
	}
	printf("->%d\n",t->num);
}
