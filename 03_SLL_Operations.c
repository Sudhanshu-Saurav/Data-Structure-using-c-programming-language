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
	int data,count,choice,index;
	struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;
    
    struct node *temp = malloc(sizeof(struct node));
    temp->data = 20;
    temp->link = NULL;
    head->link = temp;

    temp = malloc(sizeof(struct node));
    temp->data = 30;
    temp->link = NULL;
    head->link->link = temp;
        
	temp = malloc(sizeof(struct node));
    temp->data = 40;
    temp->link = NULL;
    head->link->link->link = temp;
	
	traverse(head);
	
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
			    traverse(head);
			    goto line10;
	        case 2:
				printf("\nEnter the value you want to add : ");
				scanf("%i",&data);
				system("pause");
				head = adds(head,data);
				traverse(head);
	            goto line10;
	        case 3:
				printf("Enter the value you want to add : ");
				scanf("%i",&data);
				system("pause");
				temp = addl(temp,data);
				traverse(head);
	            goto line10;
	        case 4:
		        printf("Enter the value you want to add : ");
				scanf("%i",&data);
				printf("Enter the position you want to enter : ");
				scanf("%i",&index);
				system("pause");
				addi(head,data,index);
				traverse(head);
		        goto line10;
	        case 5:
		        head = dels(head);
		        traverse(head);
	            goto line10;
	        case 6:
	            head = dell(head);
	            traverse(head);
	            goto line10;
	        case 7:
	            printf("Enter the position you want to delete : ");
			    scanf("%i",&index);
			    system("pause");
			    head = deli(head,index);
			    traverse(head);
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


void traverse(struct node *head)
{
    int count;
    if (head == NULL)
    {
        printf("Linked List is empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        printf("\nThe value of %d node is %d", count, ptr->data);
        ptr = ptr->link;
    }
    printf("\n\nTotal Number of nodes are - %d \n", count);
    
    system("pause");
}


struct node* adds(struct node *head, int data)
{
	struct node *ptr = malloc(sizeof(struct node));
	ptr -> data = data;
	ptr -> link =NULL;
	
	ptr->link = head;
	head = ptr;
	return head;
}

struct node* addl(struct node *temp, int data)
{
	struct node *ptr = malloc(sizeof(struct node));
	ptr -> data = data;
	ptr -> link =NULL;
	
	temp->link = ptr;
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


struct node* dels(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty");
    }
    else
    {
    struct node *ptr = head;
    head = head->link;
    free(ptr);
	}
  	return head;
}


struct node* dell(struct node *head)
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
    else
    {
    struct node *ptr = head;
    struct node *ptr2 = head;
    while (ptr->link != NULL)
    {
    	ptr2 = ptr;
    	ptr = ptr->link;
	}
	ptr2->link=NULL;
    free(ptr);
    ptr =NULL;
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

