#include<stdio.h>
#include<stdlib.h>
struct linked_list
{
	int num;
	struct linked_list *next;
};
typedef struct linked_list node;
node *first=NULL;
node *last=NULL;
int c=0;
node *insert(int opt,int num,node *t);
void show();
node *replace(node *t,int num,int opt);
node *del(node *t,int num);
int main()
{
	int choice,num,pos;
	node *p;
	while (1)
	{
		printf("\n1-Add \n2-Show a number at a postion \n3-Display \n4-Replace \n5-Insert \n6-Search \n7-Delete \n8-Exit \n>>>");
		scanf("%d",&choice);
		
		switch (choice)
		{
			case 1:
				printf("Enter the number\n>>>");
				scanf("%d",&num);
				p=insert(1,num,p);
				break;
				
			case 2:
				printf("Select a position(1-based index)\n>>>");
				scanf("%d",&pos);			
				if (c<pos)
					printf("Invalid Position\n");
				else
					insert(2,pos,p);
				break;
			
			case 3:
				show();
				break;
				
			case 4:
				printf("Enter the number\n>>>");
				scanf("%d",&num);
				p=replace(p,num,1);
				break;
			
			case 5:
				printf("Enter a position\n>>>");
				scanf("%d",&pos);
				if (c==pos-1)
				{
					printf("Enter the number\n>>>");
					scanf("%d",&num);
					p=insert(1,num,p);
				}
				else if(c<pos)
					printf("Invalid Position\n");
				else
					p=insert(3,pos,p);
				break;
				
			case 6:
				printf("Enter the number: ");
				scanf("%d",&num);
				p=replace(p,num,2);
				break;
			case 7:
				printf("Enter the number\n>>>");
				scanf("%d",&num);
				p=del(p,num);
				break;
			case 8:
				exit(0);
				
			default:
				printf("Invalid Option");
		}
	}
	return 1;
}
node *insert(int opt,int num,node *t)
{
	if (opt==1)
	{
		t=(node *)malloc(sizeof(node));
		if (first==NULL)
			first=t;
		else
			last->next=t;
		last=t;
		last->num=num;
		last->next=NULL;
		c++;
		return last;
	}
	else
	{
		int count=0;
		if (num==0)
		{
			if (opt==2)
				printf("%d\n",first->num);
			else
			{
				node *m=(node *)malloc(sizeof(node));
				m->num=first->num;
				printf("Enter the number\n>>>");
				scanf("%d",&first->num);
				m->next=first->next;
				first->next=m;
				first=m;
			}
			
		}
		node *p;
		for (p=first;p!=NULL,count!=num-1;p=p->next,count++)
			;
		if (opt==2)
			printf("%d\n",p->num);
		else
		{
			node *m=(node *)malloc(sizeof(node));
			m->next=p->next;
			m->num=p->num;
			p->next=m;
			printf("Enter the number\n>>>");
			scanf("%d",&p->num);
			c++;
		}
	}
}
node *replace(node *t,int num,int opt)
{
	node *p;
	int count=1;;
	int prc=0;
	for (p=first;p!=NULL;p=p->next,count++)
	{
		if (p->num==num)
		{
			if (opt==1)
			{
				printf("Enter the new number\n>>>");
				scanf("%d",&p->num);
			}
			else
			{
				printf("Found at position %d",count);
				prc=1;
			}
			break;
		}
	}
	if (prc==0)
		printf("Invalid Number\n");
	return p;
}
void show()
{
	node *t;
	for (t=first;t!=NULL;t=t->next)
		printf("->%d",t->num);
	printf("\n");
}
node *del(node *t,int num)
{
	int prc=0;
	if (first->num==num)
	{
		printf("Done");
		c--;
		first=first->next;
	}
	else
	{
		node *p;
		for (p=first;p!=NULL;p=p->next)
		{
			if (p->num==num)
			{
				node *m=first;
				while (m->next!=p)
					m=m->next;
				m->next=p->next;
				if (p==last)
					last=m;
				prc=1;
				c--;
				break;
			}
		}
		if (prc==0)
			printf("Invalid Number");
	}
	return last;
}
