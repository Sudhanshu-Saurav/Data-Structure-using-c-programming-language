#include <stdio.h>
#include <stdlib.h>
#define max 10


struct node
{
	int data;
	struct node *link;
}*top=NULL;


void print();
void add();
int del();
int empty();
int show();

int main()
{
	int choice,data,t,x;
	do
    {	
        system("cls");
        system("color A");
    	line:
        printf("\n\xB2\xB2\xB2Stack Using Linked List Operation Menu\xB2\xB2\xB2\n\n");
        printf("Press 1 to print all the elements.\n");
        printf("Press 2 to show the top element only.\n");
        printf("Press 3 to add new element.\n");
        printf("Press 4 to del the element.\n");
        printf("Press 5 to print the deleted element.\n");

        printf("Press 0 to exit\n");
        printf("\nEnter choice(0-4) : ");
        scanf("%d",&choice);
        switch (choice)
        {
	        case 1:
	        
				print(top);
				goto line;
	        case 2:
				t=show();
				if (t==0)
				{
					goto line;	
				}
				else
					printf("\nThe topmost element of stack is : %d\n\n",t);
				
				goto line;
	        case 3:
	        	
				printf("\nEnter the value you want to add : ");
				scanf("%i",&data);
				add(data);

				
			    goto line;
	        case 4:
		       	x=del(top);
	        	printf("\nThe deleted element is : %d",x);
	        	
				goto line;
			case 5:
				printf("\nThe deleted elemnt is : %d",x);
				
				goto line;
	        case 0:
	            exit(0);
	            break;
	        default:
	            printf("\n\nInvalid Choice\n\n");
	            goto line;
        }
    } while (choice != 0);
	return 0;
}


void print()
{
    int count;
    if (empty())
    {
        printf("\nStack Underflow\n\n");
        return;
    }
    struct node *ptr;
    ptr = top;
    while (ptr != NULL)
    {
        count++;
        printf("\nThe value of %d node is %d", count, ptr->data);
        ptr = ptr->link;
    }
    printf("\n\nTotal Number of nodes are - %d \n", count);
    system("pause");
}

int show()
{
	int value;
	if (empty())
	{
		printf("\n Stack Underflow\n\n");
		return;
	}
	value=top->data;
	return value;
}


void add(data)
{
	struct node *ptr;
	ptr = malloc(sizeof(struct node));
	
	if (ptr == NULL)
	{
		printf ("\nStack Overflow\n\n");
		return;
	}

	ptr -> data = data;
	ptr -> link =NULL;

	ptr->link = top;
	top = ptr;
}

int del()
{
	int value;
	struct node *ptr;
    ptr=top;
    
    if (empty())
    {
        printf("\nStack Underflow\n\n");
        return;
    }
    
    value = ptr->data;
    
    top = top->link;
    free(ptr);
    ptr = NULL;
	return value;
}


int empty()
{
	if (top == NULL)
		return 1;
	else
		return 0;
}








