#include<stdio.h>
#include<stdlib.h>
struct thread_bin_tree
{
	int num;
	struct thread_bin_tree *left,*right;
	int rthread,lthread;
};
typedef struct thread_bin_tree node;
node *root=NULL;
node *first=NULL;
int c=0;
node *next(node *t);
void insert(int num);
void show();
int main()
{
	int num,choice;
	while (1)
	{
		printf("1-Insert \n2-Delete \n3-Search \n4-Show \n5-Exit \nSelect an option: ");
		scanf("%d",&choice);
		
		switch (choice)
		{
			case 1:
				printf("Enter the number to insert: ");
				scanf("%d",&num);
				insert(num);
				break;
			
			case 2:
				if (c==0)
					printf("Empty\n");
				else
				/*{
					printf("Enter the number to delete: ");
					scanf("%d",&num);
					del(num);
				}*/
				break;
				
			case 3:
				if (c==0)
					printf("Empty\n");
				else
				/*{
					printf("Enter a number to search in the list: ");
					scanf("%d",&num);
					search(num);
				}*/
				break;
				
			case 4:
				if (c==0)
					printf("Empty\n");
				else
					show();
				break;
					
			case 5:
				exit(1);
				
			default:
				printf("Invalid Option\n");
		}
	}
	return 0;
}
void insert(int num)
{
	if (root==NULL)
	{
		c++;
		root=(node *)malloc(sizeof(node));
		root->num=num;
		root->lthread=1;
		root->rthread=1;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		int prc=0;
		node *p=root,*t;
		while (p!=NULL)
		{
			t=p;
			if (num<p->num)
			{
				if (p->lthread==0)
					p=p->left;
				else
					break;
			}
			else if (num>p->num)
			{
				if (p->rthread==0)
					p=p->right;
				else
					break;
			}
			else
			{
				prc=1;
				printf("The number is already in the tree\n");
				break;
			}
		}
		if (prc==0)
		{
			c++;
			p=(node *)malloc(sizeof(node));
			p->num=num;
			p->lthread=1;
			p->rthread=1;
			if (num>t->num)
			{
				p->right=t->right;
				t->right=p;
				t->rthread=0;
				p->left=t;
			}
			else
			{
				p->left=t->left;
				t->left=p;
				t->lthread=0;
				p->right=t;
			}
		}
	}
}
node *next(node *t)
{
	if (t->rthread==1)
		return t->right;
	else
	{
		t=t->right;
		while (t->lthread==0)
			t=t->left;
		return t;
	}
}
void show()
{
	node *p=root;
	while (p->lthread==0)
		p=p->left;
	while (p!=NULL)
	{
		printf("->%d",p->num);
		p=next(p);
	}
	printf("\n");
}
