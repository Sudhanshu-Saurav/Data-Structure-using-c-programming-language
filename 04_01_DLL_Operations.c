#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	struct node *prev;
    int data;
    struct node *next;
};

void traverseF();
void traverseB();
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
	head->prev = NULL;
	head->data = data;
	head->next = NULL;
	
	struct node *temp;
	temp=head;
	
    for(i=2;i<=n;i++)
    {
		struct node *newnode= malloc(sizeof(struct node));
		printf("Enter the number of value for %i node : ",i);
		scanf ("%i",&data);
		newnode->prev = temp;
		newnode->data = data ;
		newnode->next = NULL;
		
		temp->next = newnode;
		temp = newnode;
	}
	
	
	traverseF(head);
	
	do
    {
        system("cls");
        system("color A");
    	line10:
        printf("\n\xB2\xB2\xB2Single link list Operation Menu\xB2\xB2\xB2\n\n");
        printf("Press 1 to traverse Forward.\n");
        printf("Press 2 to traverse Backward.\n");
        printf("Press 3 to add new node at the start.\n");
        printf("Press 4 to add new node at the last.\n");
        printf("Press 5 to add new node in between.\n");
        printf("Press 6 to delete new node at the start.\n");
        printf("Press 7 to delete new node at the last.\n");
        printf("Press 8 to delete new node in between.\n");
        printf("Press 0 to exit\n");
        printf("\nEnter choice(0-9) : ");
        scanf("%d",&choice);
        switch (choice)
        {
	        case 1:
			    traverseF(head);
			    goto line10;
	        case 2:
			    traverseB(temp);
			    goto line10;
	        case 3:
				printf("\nEnter the value you want to add : ");
				scanf("%i",&data);
				system("pause");
				head = adds(head,data);
				traverseF(head);
	            goto line10;
	        case 4:
				printf("Enter the value you want to add : ");
				scanf("%i",&data);
				system("pause");
				temp = addl(temp,data);
				traverseF(head);
	            goto line10;
	        case 5:
		        printf("Enter the value you want to add : ");
				scanf("%i",&data);
				printf("Enter the position you want to enter : ");
				scanf("%i",&index);
				system("pause");
				addi(head,data,index);
				traverseF(head);
		        goto line10;
	        case 6:
		        head = dels(head);
		        traverseF(head);
	            goto line10;
	        case 7:
	            temp = dell(temp);
	            traverseF(head);
	            goto line10;
	        case 8:
	            printf("Enter the position you want to delete : ");
			    scanf("%i",&index);
			    system("pause");
			    head = deli(head,index);
			    traverseF(head);
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


void traverseF(struct node *head)
{
    int count=0;
    if (head == NULL)
    {
        printf("Linked List is empty\n");
    }
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        printf("The value of %d node is %d\n", count, ptr->data);
        ptr = ptr->next;
    }
    printf("Total Number of nodes are - %d \n", count);
}

void traverseB(struct node *temp)
{
    int count=0;
    if (temp == NULL)
    {
        printf("Linked List is empty\n");
    }
    struct node *ptr;
    ptr = temp;
    while (ptr!= NULL)
    {
        count++;
        printf("The value of %d node is %d\n", count, ptr->data);
        ptr = ptr->prev;
    }
    printf("Total Number of nodes are - %d \n", count);
}

struct node* adds(struct node *head, int data)
{
	struct node *ptr = malloc(sizeof(struct node));
	ptr -> prev = NULL;
	ptr -> data = data;
	ptr -> next =NULL;
	
	ptr->next = head;
	head->prev = ptr;
	head = ptr;
	return head;
}

struct node* addl(struct node *temp, int data)
{
	struct node *ptr = malloc(sizeof(struct node));
	ptr -> prev = NULL;
	ptr -> data = data;
	ptr -> next = NULL;
	
	temp->next = ptr;
	ptr->prev=temp;
	temp=ptr;
	return ptr;
}


struct node* addi(struct node *head, int data,int index)
{
	struct node *ptr=head;
	struct node *ptr2=head->next;
	struct node *newp=malloc(sizeof(struct node));
  	newp->prev=NULL;
	newp->data=data;
	newp->next=NULL;
	
	if(index==1)
	{
		adds(head,data);
	}
	else
	{
		index--;
		while(index!=1)
		{
			ptr=ptr->next;
			ptr2=ptr2->next;
			index--;
		}
		newp->prev = ptr;
		ptr->next = newp; 
		newp->next =ptr2;
		ptr2->prev = newp;
	}
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
    head = head->next;
    free(ptr);
	}
  	return head;
}


struct node* dell(struct node *temp)
{
    if (temp == NULL)
    {
        printf("Linked List is empty");
    }
    else
    {	
	    struct node *ptr = temp;
	    temp= temp->prev;
	    temp->next=NULL;
	
	    free(ptr);
	    ptr =NULL;
	}
  	return temp;
  	system("pause");
}


struct node* deli(struct node *head,int index)
{
    if (head == NULL)
    {
        printf("Linked List is empty");
    }
    else if (head->next == NULL)
    {
    	free(head);
    	head = NULL;
	}
    else if(index==1)
    {
    	struct node *ptr = head;
		head = head->next;
		free(ptr);
	}
	else
    {
    struct node *ptr = head;
    struct node *ptr2 = head->next;
    int i;
    for (i=1;i<index-1;i++)
    {
    	ptr = ptr->next;
    	ptr2 = ptr2->next;
	}
	ptr->next=ptr2->next;
	ptr2->next->prev=ptr;
    free(ptr2);
	}
  	return head;
  	system("pause");
}

