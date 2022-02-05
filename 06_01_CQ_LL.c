#include<stdio.h>
#include<stdlib.h>

static int count=0;
struct node
{
   int data;
   struct node *next;
};

    struct node *newnode,*temp;
    struct node *front=0,*rear=0;

void enqueue()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    int data;
	printf("\nEnter data : ");
    scanf("%d",&data);
         	
	newnode->data=data;
    newnode->next=0;
         	
	if(front==0&&rear==0)
    {
        front=rear=newnode;
        rear->next=front;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
    count++;
}

void dequeue()
{
    temp=front;
    front=front->next;
    rear->next=front;
    free(temp);
    count--;
}
         	 
void display()
{
    temp=front;
	while(temp->next!=front)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	printf("%d\n\n",temp->data);
}
			
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
				if(count==5)
					printf("\nCirculer queue is full\n");
				else
				enqueue();
				goto line;
			case 2:
				dequeue();
				goto line;
			case 3:
				display();
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




