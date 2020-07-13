#include<stdio.h>
#include<stdlib.h>
struct vertex
{
	int num;
	int state;
};
int main()
{
	/*This code is using breadth first traversal to show the vertices.My approach
	is to intialise an array of pointers to vertices and an adjacency matrix.A structure
	is created to hold the value of the vertex and it's state.By state I mean,if it has 
	been initialised or not.
	*/
	int num,n,i,j,c,m,prc,counter=0;//will use counter to keep track of elments
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	struct vertex *ver[n];//a normal array can also be used.
	int adj[n][n];
	for (i=0;i<n;i++)
	{
		prc=0;
		struct vertex *v=(struct vertex *)malloc(sizeof(struct vertex));
		v->num=i;
		v->state=0;//0 means that it's unvisited
		ver[counter++]=v;
		for (j=0;j<n;j++)
		{
			//assuming that these edges are non-directed
			if (i!=j)
			{
				printf("Is vertex %d connected to %d(1-Yes/0-No): ",i,j);
				scanf("%d",&c);
				adj[i][j]=c;
			}
			else
			{
				adj[i][j]=1;
			}
		}
	}
	/*
	//use the below code to check if vertex *ver and adjacency matrix are being 
	//properly initialized
	for (i=0;i<n;i++)
	{
		printf("%d state: %d\n",ver[i]->num,ver[i]->state);
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}
	*/
	int count=0;
	prc=0;
	printf("%d ",ver[count]->num);
	//count is used to increment the vertex array
	ver[count]->state=1;
	/*At the beginning of each iteration, I have checker if all the elements have
	been visited or not.If not then the loop continues.*/
	while (prc==0)
	{
		//the below loop is used to check if there are any numbers left to visit
		for (i=0;i<n;i++)
		{
			if (ver[i]->state==0)
				break;
		}
		if (i==n)
			prc=1;
		else
		{
			
			//this for is for checking if the neighbours of the current vertex have been visited or not.
			for (i=0;i<n;i++)
			{
				if (adj[count][i]==1 && ver[i]->state==0)
				{
					printf("%d ",ver[i]->num);
					ver[i]->state=1;
				}
			}
		}
		count++;
	}
	return 0;
}
