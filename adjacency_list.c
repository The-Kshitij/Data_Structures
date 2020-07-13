#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *next;
};
int main()
{
	int i,j,num,n;
	printf("How many nodes are there: ");
	scanf("%d",&n);
	struct node vertex[n];
	struct node *t,*k;
	for (i=0;i<n;i++)
	{
		k=&vertex[i];
		k->num=i;
		t=NULL;
		while (1)
		{
			printf("Enter a node to which %d is connected(-1 to stop): ",i);
			scanf("%d",&num);
			if (num==-1)
			{
				k->next=t;
				break;
			}
			else
			{
				t=(struct node *)malloc(sizeof(struct node));
				t->num=num;
				t->next=NULL;
				k->next=t;
				k=t;
				t=t->next;
			}
		}
	}
	printf("Following are the connections: \n");
	for (i=0;i<n;i++)
	{
		printf("Vertex %d is connected to: ",i);
		t=vertex[i].next;
		int c=0;
		while (t!=NULL)
		{
			printf("%d ",t->num);
			c++;
			t=t->next;
		}
		if (c==0)
			printf("None");
		printf("\n");
	}
	return 0;
}
