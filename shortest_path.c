#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,k,n;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	int p[n][n],sp[n][n];
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			printf("Is %d connected to %d(1-Yes/0-No): ",i,j);
			scanf("%d",&p[i][j]);
			if (p[i][j]==0)
				sp[i][j]=n*n+1;
			else
				sp[i][j]=p[i][j];
		}
	}
	for (k=0;k<n;k++)
	{
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				sp[i][j]=sp[i][j]<(sp[i][k]+sp[k][j])?sp[i][j]:(sp[i][k]+sp[k][j]);
			}
		}
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (sp[i][j]==n*n+1)
				printf("None ");
			else
				printf("%d ",sp[i][j]);
		}
		printf("\n");
	}
	return 0;
}
