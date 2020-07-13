#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,size,num,c=0,j;
	printf("Size: ");
	scanf("%d",&size);
	int arr[size];
	while (1)
	{
		int state=0;
		printf("1)Push 2)Pop 3)Show 4)Search 5)Exit\n:");
		scanf("%d",&i);
		
		switch (i)
		{
		case 1:
			if (c==size)
				printf("!!STACK OVERFLOW!!\n");
			else
			{
				printf("Number: ");
				scanf("%d",&num);
				arr[c]=num;
				c++;
			}
			break;
		
		case 2:
			if (c==0)
				printf("!!STACK UNDERFLOW!!\n");
			else
				c--;				
			break;
			
		case 3:
			if (c==0)
				printf("Empty\n");
			else
			{
				for (j=0;j<c;j++)
					printf("%d ",arr[j]);
				printf("\n");
			}
			break;

		case 4:
			if (c==0)
				printf("Empty\n");
			else
			{
				printf("Number: ");
				scanf("%d",&num);
				for (j=0;j<c;j++)
					if (arr[j]==num)
					{
						printf("%d found at %d\n",num,j);
						state=1;
						break;
					}
				if (state==0)
					printf("%d not found\n",num);
			}
			break;
			
		case 5:
			exit(0);
		
		default:
			printf("!!INVALID COMMAND!!\n");
		}
	}
	return 1;
}
