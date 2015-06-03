#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
struct node{
	int data;
	struct node *lc,*rc;
}typedef Node;

Node * newNode(int d){
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->lc = NULL;
	tmp->rc = NULL;
	tmp->data = d;
	return tmp;
}
Node* insert(Node *root,int data){
	if(root == NULL)
	return newNode(data);
	Node *prev = NULL;
	while(root){
		prev = root;
		
		if(data <= root->data)
			root = root->lc;
		else
			root = root->rc; 
	}
	if(data <= prev->data)
	prev->lc = newNode(data);
	else
	prev->rc = newNode(data);
	return root;
}
Node * insertRecursive(Node *root, int data){
	if(root == NULL)
	return newNode(data);
	
	if(data <= root->data)
	root->lc = insertRecursive(root->lc, data);
	else if(data > root->data)
	root->rc = insertRecursive(root->rc, data);
	return root;
}
void inorderTraversal(Node *root){
	static int i=1;
	printf("\n%d ",i++);
	
	if(root){
	printf("\n%d ",i++);
		inorderTraversal(root->lc);
		printf("%d ",root->data);
		inorderTraversal(root->rc);
	}
}

bool searcInBST(Node *root, int data){
	while(root){
		if(root->data == data)
		return true;
		if(data < root->data)
		root = root->lc;
		else 
		root = root->rc;
	}
	return false;
}
Node * searchInBSRrecur(Node *root, int data,Node **parent){
	if(root == NULL)
	return NULL;
	if(root->data == data){
		*parent = NULL;
		return root;
	}
	if(root->lc->data == data){
		*parent = root;
		return root->lc;
	}
	if(root->rc->data == data){
		*parent = root;
		return root->rc;
	}
	if(data < root->data)
	return searchInBSRrecur(root->lc,data,parent);
	
	return searchInBSRrecur(root->rc,data,parent);
}
bool delete(Node *root, int data){
	if(root == NULL){
		printf("\nNothing to be deleted!\n");
		return false;
	}
	Node *parent = NULL;
	Node *toBeDelted = searchInBSRrecur(root,data,&parent);
	
	if(toBeDelted == NULL){
		printf("\nNothing to be deleted!\n");
		return false;
	}
	else
	printf("\nNode be deleted is %d, child of %d\n",toBeDelted->data,parent->data);
	
	if(toBeDelted->lc == NULL && toBeDelted->rc == NULL){
		if(toBeDelted == parent->rc){
		parent->rc = NULL;
		}
		if(toBeDelted == parent->lc){
		parent->lc = NULL;
		}
	free(toBeDelted);
	printf("\nafter deletion inoder traversal of the BST\n");
    inorderTraversal(root);
	return true;
	}
	
	if(toBeDelted->lc == NULL){
		Node *t = toBeDelted;
		if(toBeDelted == parent->lc){
			parent->lc = toBeDelted
		}
		toBeDelted = toBeDelted->rc;
		free(t);
		return true;
	}
	
	if(toBeDelted->rc == NULL){
		Node *t = toBeDelted;
		toBeDelted = toBeDelted->lc;
		free(t);
		return true;
	}
	
	if(toBeDelted->lc != NULL && toBeDelted->rc != NULL){
		if(toBeDelted->rc){
		Node *t = 	toBeDelted->rc;
		for(; t->lc != NULL; t=t->lc );
			//toBeDelted->data = t->data;
			return delete(root,t->data);
		}
	}
}

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    //inserting using insertRecursive
    
    insertRecursive(root,10);
    insertRecursive(root,100);
         
    printf("\nprint inoder traversal of the BST\n");
    inorderTraversal(root);
    
    if(searcInBST(root,40))
    printf("\n40 found in BST");
    else
    printf("\n40 NOT found in BST");
        
    if(searcInBST(root,400))
    printf("\n400 found in BST");
    else
    printf("\n400 NOT found in BST");
    
    if(delete(root,40))
    printf("\n40 deleted from BST");
    else
    printf("\n40 NOT found in BST for deletion");
    
    //printf("\nprint inoder traversal of the BST\n");
    //inorderTraversal(root);

    if(delete(root,400))
    printf("\n400 deleted from BST");
    else
    printf("\n400 NOT found in BST for deletion");
    /*
    printf("\nprint inoder traversal of the BST\n");
    inorderTraversal(root);

    
    if(delete(root,20))
    printf("\n20 deleted from BST");
    else
    printf("\n20 NOT found in BST for deletion");
    
    printf("\nprint inoder traversal of the BST\n");
    inorderTraversal(root);

    
    if(delete(root,50))
    printf("\n50 deleted from BST");
    else
    printf("\n50 NOT found in BST for deletion");
 */   
    printf("\nprint inoder traversal of the BST\n");
    inorderTraversal(root);

    
  	printf("\n");
    return 0;
}
