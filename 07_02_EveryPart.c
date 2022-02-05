#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

struct tree
{
	struct tree* left;
	char data[10];
	struct tree* right;
};

typedef struct tree node;
static int ctr,count;
node* tree[100];
node* getnode();
void createbt();
void inorder(node *root);
void preorder(node *root);
void print_leaf(node *root);
int count_node(node *root);
int isFullTree(node* root);
int isComplete(node* root,int index, int number_nodes);

int main()
{
 	int i,choice;
 	int node_count = count_node(tree[0]);
 	int index = 0;
 	createbt();
 	system("cls");
 	system("color A");
 	line:
 	
 	printf("\n 1.Inorder Traversal ");
 	printf("\n 2.Preorder Traversal ");
 	printf("\n 3.Count total Nodes ");
 	printf("\n 4.Count Leaf Nodes ");
 	printf("\n 5.Is tree full ? \n");
 	
 	printf("\n 0.Exit");
 	
 	printf("\n Enter choice (0-4) : ");
 	scanf("%d",&choice);
 	switch(choice)
 	{
 		case 1:
 			printf("\n");
 			inorder(tree[0]);
 			printf("\n");
 			goto line;
		case 2:
			printf("\n");
			preorder(tree[0]);
			printf("\n");
			goto line;
		case 3:
			printf("\n");
			count_node(tree[0]);
			printf(" Total number of nodes is : %d\n",count);
			goto line;
		case 4:
			printf("\n");
			printf(" Leaf nodes are : ");
			print_leaf(tree[0]);
			printf("\n");
			goto line;
		case 5:
		    if (isFullTree(tree[0]))
		        printf("\n Tree is full\n");
		    else
		        printf("\n Tree is not full\n");
			goto line;
		case 6:
			if (isComplete(tree[0], index, node_count))
        		printf("\n Tree is complete\n");
   			else
        		printf("\n Tree is not complete\n");
        	goto line;
		case 0:
			exit(0);
		default :
			printf("\nInvalid choice");
			goto line;
	}
	return 0;
}

node* getnode()
{
	node *temp ;
	temp = (node*) malloc(sizeof(node));
	printf("\n Enter Data: ");
	scanf("%s",temp->data);
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


void createbt()
{
	int j, i=0;
	printf("\n How many nodes you want: ");
	scanf("%d",&ctr);
	tree[0] = getnode();
	j = ctr;
	j--;
	do
	{
	 	if( j > 0 ) 
	 	{
			tree[ i * 2 + 1 ] = getnode();
			tree[i]->left = tree[i * 2 + 1];
	 		j--;
		}
	 	if( j > 0 ) 
	 	{
			tree[i * 2 + 2] = getnode();
	 		j--;
			tree[i]->right = tree[i * 2 + 2];
	 	}
	 	i++;
	} while( j > 0);
}


void inorder(node *root)
{
	if( root != NULL )
 	{
		inorder(root->left);
 		printf("%3s",root->data);
 		inorder(root->right);
 	}
}


void preorder(node *root)
{
	if( root != NULL )
 	{
 		printf("%3s",root->data);
 		preorder(root->left);
 		preorder(root->right);
 	}
}


void print_leaf(node *root)
{
	if(root != NULL)
 	{
		if(root->left == NULL && root->right == NULL)
 		printf("%3s",root->data);
 		print_leaf(root->left);
 		print_leaf(root->right);
 	}
}

int count_node(node *root)
{
	if(root != NULL)
 	{
 		count_node(root->left);
 		count++;
 		count_node(root->right);
 	}
 	return count;
}

int isFullTree(node* root)
{
    if (root == NULL)
        return 1;
  
    if (root->left == NULL && root->right == NULL)
        return 1;
  
    if ((root->left) && (root->right))
        return (isFullTree(root->left) && isFullTree(root->right));
        
    return 0;
}



int isComplete (node* root, int index, int number_nodes)
{
    if (root == NULL)
        return (1);
    if (index >= number_nodes)
        return (0);
    return (isComplete(root->left, 2*index + 1, number_nodes) && isComplete(root->right, 2*index + 2, number_nodes));
    
}
 
