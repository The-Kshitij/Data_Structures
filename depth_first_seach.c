#include<stdio.h>
struct vertex
{
	int num;
	int state;
};
int main()
{
	int n,i,j,counter=0,c;
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	struct vertex ver[n];
	int adj[n][n],visited[n],front=0,rear=0,prc;
	for (i=0;i<n;i++)
	{
		prc=0;
		ver[i].num=i;
		ver[i].state=0;
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
	counter=0;
	while (1)
	{
		prc=0;
		for (i=0;i<n;i++)
		{
			if (ver[i].state==0)
				break;
		}
		if (i==n)
			break;
		for (i=0;i<n;i++)
		{
			if (adj[counter][i]==1 && ver[i].state==0)
			{
				printf("%d ",ver[i].num);
				visited[rear++]=i;
				ver[i].state=1;
				prc=1;
				counter=ver[i].num;
				break;
			}
		}
		if (prc==0)
			counter=visited[front++];
	}
	return 0;
}
