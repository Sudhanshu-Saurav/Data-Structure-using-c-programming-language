#include <stdio.h>
#include <stdlib.h>
#define max 10


int stack_arr[max];
int top=-1;


int print();
int show();
int push();
int del();
int full();
int empty();



int main()
{
	int choice,data,index,t,n,x;
	do
    {
        system("cls");
        system("color A");
    	line:
        printf("\n\xB2\xB2\xB2Stack Using Array Operation Menu\xB2\xB2\xB2\n\n");
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
				print();
				
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
	        	printf("Enter the number of values you want to enter :");
	        	scanf("%d",&n);
	        	int i;
				for(i=1;i<=n;i++)
				{
		        	printf("Enter the %d element : ",i);
		        	scanf("%d",&data);
	        		push(data);
	        	}
	        	
			    goto line;
	        case 4:
	        	x=del();
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


int print()
{
	int i,count=0;
	if (top==-1)
	{
		printf("\nStack Underflow\n\n");
		return;
	}
	else
	{
		printf("\n\n");
		for(i=top;i>=0;i--)
		{
			count++;
			printf("The Value of %d position element is : %d\n",count,stack_arr[i]);
		}
	}
}


int show()
{
	if (empty())
	{
		printf("\nStack Underflow\n\n");
		return;
	}
	else
	{
		return stack_arr[top];
	}
}


int push(data)
{
	if (full())
	{
		printf ("\nStack Overflow");
		return;
	}
	else
	{
		top=top+1;
		stack_arr[top]=data;
	}
}


int del()
{
	int value;
	if (empty())
	{
		printf("\n Stack Underflow");
		return;
	}
	else
	{
		value = stack_arr[top];
		top=top-1;
		return value;
	}
}


int full()
{
	if (top==max-1)
		return 1;
	else
		return 0;
}


int empty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}







