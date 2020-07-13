#include<stdio.h>
#include<stdlib.h>
int c=0;
void ins(int n,int queue[]);
void rem(int queue[]);
void show(int queue[]);
void main()
{
	int i,num,n,size;
	printf("Enter the array size: ");
	scanf("%d",&size);
	int queue[size];
	
	while (1)
	{
		printf("1)Insert\n2)Remove\n3)Show\n4)Exit\n:");
		scanf("%d",&i);
		switch (i)
		{
			case 1:
				if (c==size)
					printf("!!Full!!\n");
				else
				{
					printf("Number: ");
					scanf("%d",&num);
					ins(num,queue);
					c++;
				}
				break;
		
		 	case 2:
		 		if (c==0)
		 			printf("!!Empty!!\n");
		 		else
		 		{
		 			rem(queue);
		 			c--;
				}
		 		break;
		 	
		 	case 3:
		 		if (c==0)
		 			printf("!!Empty!!\n");
		 		else
		 			show(queue);
		 		break;
		 		
		 	case 4:
		 		exit(0);
		 		
		 	default:
		 		printf("!!INVALID COMMAND!!\n");
		}
	}
}
void ins(int n,int queue[])
{
	queue[c]=n;
}
void rem(int queue[])
{
	int i;
	for (i=1;i<c;i++)
		queue[i-1]=queue[i];
}
void show(int queue[])
{
	int i;
	for (i=0;i<c;i++)
		printf("%d ",queue[i]);
	printf("\n");
}
