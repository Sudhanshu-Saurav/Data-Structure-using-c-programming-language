#include<stdio.h>
#include<stdlib.h>

struct bt
{
	struct bt *left;
 	int data;
 	struct bt *right;
};
 
struct bt* insert(struct bt *,int);
void inorder(struct bt *);
void preorder(struct bt *);
void postorder(struct bt *);
 
int main ()
{
	struct bt *r=NULL;
  	r=insert(r,30);
  	r=insert(r,15);
  	r=insert(r,10);
  	r=insert(r,20);
  	r=insert(r,40);
  	r=insert(r,5);
  	r=insert(r,45);
  	r=insert(r,35);
  	
	printf("\nDisplay element in inorder:-");
  	  inorder(r);
  	printf("\nDisplay element in preorder:-");
  	  preorder(r);
  	printf("\nDisplay element in postorder:-");
  	  postorder(r);
	  return 0;	 
} 
   
   
struct bt * insert(struct bt *q,int val)
{
    struct bt *temp;
    temp=(struct bt *)malloc(sizeof(struct bt));
      
    if(q==NULL)
    { 
    	temp->data=val;
    	temp->left=temp->right=NULL;
    	return temp;
	}
	else
	{
		if(val<(temp->data))
		{
		  	q->left=insert(q->left,val);
		}
		else
		{
		  	q->right=insert(q->right,val);
		}
	}
	return q; 
}
	
	
 void inorder(struct bt *q)
{
	if(q!=NULL)
	{
	 	inorder(q->left);
		printf(" %d ",q->data);
		inorder(q->right);return;
	}
	      
	
}
	
	
void preorder(struct bt *q)
{
	if(q!=NULL)
	{
		printf(" %d ",q->data);
		preorder(q->left);
		preorder(q->right);
	}     
}
	 
void postorder(struct bt *q)
{
	if(q!=NULL)
	{
	 	postorder(q->left);
		postorder(q->right);	
		printf(" %d ",q->data);
	}
}
