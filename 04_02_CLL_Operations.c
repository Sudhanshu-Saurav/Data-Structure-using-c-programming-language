#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void traverse();
struct node* adds();
struct node* addl();
struct node* addi();
struct node* dels();
struct node* dell();
struct node* deli();

int main()
{
	int i,n,data,choice,index;
	printf("Enter the number of nodes you want to create : ");
	scanf ("%i",&n);
	printf("Enter the number of value for 1 node : ");
	scanf ("%i",&data);
	struct node *head = malloc(sizeof(struct node));
	head->data=data;
	head->link= NULL;

	struct node *temp;
	temp=head;

	for (i=2;i<=n;i++)
	{
		struct node *newnode= malloc(sizeof(struct node));
		printf("Enter the number of value for %i node : ",i);
		scanf ("%i",&data);
		newnode->data = data ;
		newnode->link = NULL;
		temp->link=newnode;
		temp= newnode;
	}
	temp->link=head;
	
	traverse(head,temp);
	
	do
    {
        system("cls");
        system("color A");
    	line10:
        printf("\n\xB2\xB2\xB2Single link list Operation Menu\xB2\xB2\xB2\n\n");
        printf("Press 1 to traverse.\n");
        printf("Press 2 to add new node at the start.\n");
        printf("Press 3 to add new node at the last.\n");
        printf("Press 4 to add new node in between.\n");
        printf("Press 5 to delete new node at the start.\n");
        printf("Press 6 to delete new node at the last.\n");
        printf("Press 7 to delete new node in between.\n");
        printf("Press 0 to exit\n");
        printf("\nEnter choice(0-9) : ");
        scanf("%d",&choice);
        switch (choice)
        {
	        case 1:
			    traverse(head,temp);
			    goto line10;
	        case 2:
				printf("\nEnter the value you want to add : ");
				scanf("%i",&data);
				system("pause");
				head = adds(head,data,temp);
				traverse(head,temp);
	            goto line10;
	        case 3:
				printf("Enter the value you want to add : ");
				scanf("%i",&data);
				system("pause");
				temp = addl(head,temp,data);
				traverse(head,temp);
	            goto line10;
	        case 4:
		        printf("Enter the value you want to add : ");
				scanf("%i",&data);
				printf("Enter the position you want to enter : ");
				scanf("%i",&index);
				system("pause");
				addi(head,data,index);
				traverse(head,temp);
		        goto line10;
	        case 5:
		        head = dels(head,temp);
		        traverse(head,temp);
	            goto line10;
	        case 6:
	            temp = dell(head,temp);
	            traverse(head,temp);
	            goto line10;
	        case 7:
	            printf("Enter the position you want to delete : ");
			    scanf("%i",&index);
			    system("pause");
			    head = deli(head,index);
			    traverse(head,temp);
	            goto line10;
	        case 0:
	            exit(0);
	            break;
	        default:
	            printf("\n\nInvalid Choice\n\n");
	            goto line10;
        }
    } while (choice != 0);
	return 0;
}


void traverse(struct node *head,struct node *temp)
{
    int count;
    if (head == NULL)
    {
        printf("Linked List is empty");
    }
    struct node *ptr = NULL;
    ptr = temp->link;
    do 
    {
        count++;
        printf("\nThe value of %d node is %d", count, ptr->data);
        ptr = ptr->link;
    }
    while(ptr != temp->link);
    printf("\n\nTotal Number of nodes are - %d \n", count);
    
    printf("The value after circulating from last node is %d\n\n",temp->link->data);
    
    system("pause");
}


struct node* adds(struct node *head, int data,struct node *temp)
{
	struct node *ptr = malloc(sizeof(struct node));
	ptr -> data = data;
	ptr -> link =NULL;
	
	ptr->link = head;
	head = ptr;
	temp->link=head;
	return head;
}

struct node* addl(struct node *head,struct node *temp, int data)
{
	struct node *ptr = malloc(sizeof(struct node));
	ptr -> data = data;
	ptr -> link =NULL;
	
	temp->link = ptr;
	temp=ptr;
	temp->link=head;
	return ptr;
}


struct node* addi(struct node *head, int data,int index)
{
	struct node *ptr=head;
	struct node *ptr2=malloc(sizeof(struct node));
	ptr2->data=data;
	ptr2->link=NULL;
	
	index--;
	while(index!=1)
	{
		ptr=ptr->link;
		index--;
	}
	ptr2->link = ptr->link;
	ptr->link = ptr2;

}


struct node* dels(struct node *head,struct node *temp)
{
    if (head == NULL)
    {
        printf("Linked List is empty");
    }
    else
    {
    struct node *ptr = head;
    head = head->link;
    temp->link=head;
    free(ptr);
	}
  	return head;
}


struct node* dell(struct node *head,struct node *temp)
{
    if (head == NULL)
    {
        printf("Linked List is empty");
    }
    else
    {
    struct node *ptr = head;
    while (ptr->link != temp)
    {
   		ptr = ptr->link;
    }
    ptr->link=head;
    temp->link=NULL;
    free(temp);
    temp=ptr;
	}
  	return head;
}


struct node* deli(struct node *head,int index)
{
    if (head == NULL)
    {
        printf("Linked List is empty");
    }
    else if (head->link == NULL)
    {
    	free(head);
    	head = NULL;
	}
    else if(index==1)
    {
    	struct node *ptr = head;
		head = head->link;
		free(ptr);
	}
	else
    {
    struct node *ptr = head;
    struct node *ptr2 = head->link;
    int i;
    for (i=1;i<index-1;i++)
    {
    	ptr = ptr->link;
    	ptr2 = ptr2->link;
	}
	ptr->link=ptr2->link;
    free(ptr2);
	}
  	return head;
}

