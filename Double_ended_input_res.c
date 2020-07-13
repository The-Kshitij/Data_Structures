#include<stdio.h>
#include<stdlib.h>
struct double_ended_queue
{
	int num;
	struct double_ended_queue *next;	
};
typedef struct double_ended_queue node;
int c=0;
node *first=NULL;
node *last=NULL;
void insert(int num);
void show();
void del(int pos);
int main()
{
	int num,choice,pos;
	while (1)
	{
		printf("1-Insert a number \n2-Delete \n3-Show \n4-Exit \nSelect an option: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				//printf("Current Length: %d\n",c);
				printf("Enter the number: ");
				scanf("%d",&num);
				insert(num);
				c++;
				break;
			
			case 2:
				if (c==1)
				{
					printf("Both ends are same\nDeleted\n");
					c--;
					first=NULL;
					last=NULL;
				}
				else if (c!=0)
				{
					printf("From which end do you want to delete \n1-First\n2-Last \nSelect an option: ");
					scanf("%d",&pos);
					del(pos);
					c--;
				}
				else
					printf("Empty\n");
				break;
			
			case 3:
				if (c==0)
					printf("Empty\n");
				else
					show();
				break;
				
			case 4:
				exit(1);
			
			default:
				printf("Invalid Option\n");
		}
	}
	return 0;	
}
void insert(int num)
{
	node *t=(node *)malloc(sizeof(node));
	t->num=num;
	t->next=NULL;
	if (first==NULL)
	{
		first=t;
		last=t;
	}
	else
	{
		last->next=t;
		last=t;
	}
}
void del(int pos)
{
	node *p;
	if (pos==1)
	{
		p=first->next;
		free(first);
		first=p;
		printf("Deleted\n");
	}
	else if (pos==2)
	{
		p=first;
		while (p->next!=last)
			p=p->next;
		p->next=NULL;
		free(last);
		last=p;
		printf("Deleted\n");
	}
	else
		printf("Invalid Position\n");
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
