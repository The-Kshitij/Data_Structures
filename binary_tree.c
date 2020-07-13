#include<stdio.h>
#include<stdlib.h>
struct binary_tree
{
	int num;
	struct binary_tree *left;
	struct binary_tree *right;
};
int c=0;
typedef struct binary_tree node;
node *root=NULL;
node *insert(node *p,int num);
void show(node *p,int choice);
node *del(node *p,int num);
int main()
{
	int num,choice,i;
	while (1)
	{
		printf("\n1-Insert a number \n2-Delete number \n3-Search \n4-Show \n5-Exit \nSelect an option: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter the number: ");
				scanf("%d",&num);
				root=insert(root,num);
				c++;
				break;
				
			case 2:
				if (c==0)
					printf("Empty\n");
				else
				{
					if (c==1)
					{
						printf("Enter the number to delete: ");
						scanf("%d",&num);
						if (num==root->num)
						{
							printf("Deleted\n");
							free(root);
							root=NULL;
							c=0;
						}
						else
							printf("Number is not in the list\n");
					}
					else
					{
						printf("Enter the number to delete: ");
						scanf("%d",&num);
						del(root,num);	
					}
				}
				break;
			
			case 3:
				if (c==0)
					printf("Empty\n");
				else
				{
					printf("Enter the number to search in the tree: ");
					scanf("%d",&num);
					i=search(root,0,num);
					if (i!=0)
						printf("The number is in the list\n");
					else
						printf("The number is not in the list\n");
				}
				break;
				
			case 4:
				if (c==0)
					printf("Empty\n");
				else
				{
					printf("1-Preorder \n2-Inorder \n3-Postorder\nSelect an option: ");
					scanf("%d",&num);
					show(root,num);
				}
				break;
				
			case 5:
				exit(1);
				
			default:
				printf("Invalid Choice\n");
		}
	}
	return 0;
}
node *insert(node *p,int num)
{
	if (root==NULL)
	{
		p=(node *)malloc(sizeof(node));
		p->num=num;
		p->left=NULL;
		p->right=NULL;
		root=p;
	}
	else
	{
		if (p==NULL)
		{
			p=(node *)malloc(sizeof(node));
			p->left=NULL;
			p->num=num;
			p->right=NULL;
		}
		else if (num>p->num)
			p->right=insert(p->right,num);
		else if (num<p->num)
			p->left=insert(p->left,num);
		else
			printf("Number is already present\n");
	}
	return p;
}
void show(node *p,int choice)
{
	if (p!=NULL)
	{
		if (choice==1)
		{
			printf("->%d",p->num);
			if (p->left!=NULL)
				show(p->left,choice);
			if (p->right!=NULL)
				show(p->right,choice);
		}
		else if (choice==2)
		{
			if (p->left!=NULL)
				show(p->left,choice);
			printf("->%d",p->num);
			if (p->right!=NULL)
				show(p->right,choice);
		}
		else if (choice==3)
		{
			if (p->left!=NULL)
				show(p->left,choice);
			if (p->right!=NULL)
				show(p->right,choice);
			printf("->%d",p->num);
		}
		else
		{
			printf("Invalid Method\n");
		}
	}
}
int search(node *p,int i,int num)
{
	if (p!=NULL)
	{
		if (p->num<num)
		{
			i=search(p->right,i,num);
		}
		else if (p->num>num)
		{
			i=search(p->left,i,num);
		}
		else
			return 1;
	}
	return i;
}
node *del(node *p,int num)
{
	if (p!=NULL)
	{
		if (p->num<num)
		{
			p->right=del(p->right,num);
		}
		else if (p->num>num)
		{
			p->left=del(p->left,num);
		}
		else
		{
			if (p->left==NULL && p->right==NULL)
			{
				free(p);
				printf("Deleted\n");
				c--;
				return NULL;
			}
			else if (p->right==NULL && p->left!=NULL)
			{
				p->num=p->left->num;
				p->left->num=num;
				p->left=del(p->left,num);
			}
			else
			{
				p->num=p->right->num;
				p->right->num=num;
				p->right=del(p->right,num);
			}
		}
		return p;
	}
}
