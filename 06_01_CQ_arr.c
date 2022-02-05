#include <stdio.h>
#include <stdlib.h>
#define max 5

static int count=0;
int cq[max],value,x;
int front = -1;
int rear = -1;
void enqueue();
void dequeue();
void print();


int main()
{
	int choice;
	system("cls");
	system("color A");
	do
	{
		line:
		printf("\nPress 1 to add value to circular queue");
		printf("\nPress 2 to del value from circular queue");
		printf("\nPress 3 to print all the values of circular queue");
		printf("\nPress 0 to exit");
		
		printf("\n\nEnter choice (0-3) : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if(count==max)
					printf("\nCircular queue id full\n");
				else
				enqueue(value);
				goto line;
			case 2:
				dequeue();
				goto line;
			case 3:
				print();
				goto line;
			case 0:
				exit(0);
				break;
			default:
				printf("\n\nInvalid Choice\n\n");
	            goto line;
		}
	} while(choice!=0);
	return 0;
}




void enqueue()
{
	if(count==max)
	{
		printf("\ncircular queue is full\n");
	}
	else
	{
		printf("\nEnter the value you want to add : ");
		scanf("%d",&value);
		cq[rear] = value;
		rear = (rear+1) % max;
		
	}
	count++;
}

void dequeue()
{

	if(count == 0)
	{
		printf("\ncircular queue is empty\n");
	}
	else
	{
		
		x = cq[front];
		front = (front +1) % max;
		count--;
	}

}

void print()
{
	if(count == 0)
	{
		printf("\ncircular queue is empty\n");
	}
	else
	{

		if(rear>front)
		{
			int i;
			for(i=front;i<rear;i++)
			{
				printf("%d\n",cq[i]);
			}
		}
		else
		{
			int i;
			for(i=front;i<max;i++)
			{
				printf("%d\n",cq[i]);
			}
			for(i=0;i<rear;i++)
			{
				printf("%d\n",cq[i]);
			}
		}
	}
}


