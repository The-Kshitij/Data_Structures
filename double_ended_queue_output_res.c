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
void insert(int num,int pos);
void show();
void del();
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
				if (c==0)
				{
					printf("Both the ends are same\n");
					pos=1;
				}
				else
				{
					printf("To which end do you want to add \n1-Starting \n2-End \nSelect an option: ");
					scanf("%d",&pos);
				}
				insert(num,pos);
				c++;
				break;
			
			case 2:
				if (c==1)
				{
					first=NULL;
					last=NULL;
					c--;
					printf("Deleted\n");
				}
				else if (c==0)
					printf("Empty\n");
				else
				{
					printf("Deleted\n");
					del();
					c--;
				}
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
void insert(int num,int pos)
{
	node *t=(node *)malloc(sizeof(node));
	t->num=num;
	if (first==NULL)
	{
		first=t;
		last=t;
		t->next=NULL;
	}
	else
	{
		if (pos==1)
		{
			t->next=first;
			first=t;
		}
		else if (pos==2)
		{
			last->next=t;
			t->next=NULL;
			last=t;
		}
		else
			printf("Invalid Position\n");
	}
}
void del()
{
	node *p=first->next;
	free(first);
	first=p;
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
