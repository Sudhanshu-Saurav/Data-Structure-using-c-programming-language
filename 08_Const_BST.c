#include <stdio.h>
#include <stdlib.h>

struct node 
{
	struct node* leftchild;
	int data;
	struct node* rightchild;
};

struct node *newNode(int item);
struct node* insert(struct node *node, int data);
struct node *minValueNode(struct node *node);
struct node *deleteNode(struct node *root, int data);
void inorder(struct node *root);
void preorder(struct node *root);

int main() 
{
	int a,b,c,choice;
	struct node *root = NULL;
	line:
	do
	{
		printf("\n\n1.Insert node");
		printf("\n2.Delete node");
		printf("\n3.Inorder traverse");
		printf("\n4.preorder traverse");
		printf("\n\n0.Exit");
		
		printf("\n\nEnter(0-4) : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the value to add : ");
				scanf("%d",&a);
				root=insert(root,a);
				inorder(root);
				goto line;
			case 2:
				printf("\nEnter the value to delete : ");
				scanf("%d",&b);
				root=deleteNode(root,b);
				inorder(root);
				goto line;	
			case 3:
				inorder(root);
				goto line;
			case 4:
				preorder(root);
				goto line;				
			case 0:
				exit(0);
				break;
			default:
				printf("\nInvalid input");
				goto line;
		}	
	}while(choice!=0);
	return 0;
}


struct node *newNode(int item) 
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->leftchild = NULL;
  temp->data = item;
  temp->rightchild= NULL;
  return temp;
}


struct node* insert(struct node *node, int data) 
{
	if (node == NULL)
		return newNode(data);
  	
	if (data < node->data)
    	node->leftchild = insert(node->leftchild, data);
  	else
    	node->rightchild= insert(node->rightchild, data);
	return node;
}


struct node *minValueNode(struct node *node)
{
	struct node *current = node;
	while (current && current->leftchild != NULL)
	current = current->leftchild;
	return current;
}


struct node *deleteNode(struct node *root, int data)
{
  	if (root == NULL)
	  	return root;
  	if (data < root->data)
    	root->leftchild = deleteNode(root->leftchild, data);
  	else if (data > root->data)
   		root->rightchild= deleteNode(root->rightchild, data);

  	else 
  	{
	    if (root->leftchild == NULL)
		{
		    struct node *temp = root->rightchild;
		    free(root);
		    return temp;
	    } 
		else if (root->rightchild== NULL)
		{
		    struct node *temp = root->leftchild;
		    free(root);
		    return temp;
	    }
	    struct node *temp = minValueNode(root->rightchild);
	    root->data = temp->data;
	    root->rightchild= deleteNode(root->rightchild, temp->data);
  	}
  return root;
}



void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->leftchild);
		printf("%d\t", root->data);
		inorder(root->rightchild);
  	}
}

void preorder(struct node *root)
{
	if (root != NULL)
	{
		printf("%d\t", root->data);
		preorder(root->leftchild);
		preorder(root->rightchild);
  	}
}
