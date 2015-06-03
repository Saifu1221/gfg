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
	//printf("\n%d ",i++);
	
	if(root){
	//printf("\n%d ",i++);
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
Node *getInorderSucc(Node *node){
 	while(node->lc)
 	node = node->lc;
 	return node;
}
Node* delete(Node *root, int data){
	if(root == NULL)
	return root;
	
	if(data < root->data)
	root->lc = delete(root->lc,data);
	else if(data > root->data)
	root->rc = delete(root->rc,data);
	else{
		if(root->lc == NULL && root->rc == NULL){
		free(root);
		return NULL;
		}
		if(root->lc == NULL){
		Node *temp = root->rc;
		free(root);
		return temp;
		}
		if(root->rc == NULL){
		Node *temp = root->lc;
		free(root);
		return temp;
		}
		
		Node *inOrderSucc = getInorderSucc(root->rc);
		root->data =  inOrderSucc->data;
		root->rc = delete(root->rc,inOrderSucc->data);
	
	}
	return root;
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
    
    printf("\nprint inoder traversal of the BST\n");
    inorderTraversal(root);
    printf("\nDeleting 20..");
    delete(root,20);
    printf("\nprint inoder traversal of the BST\n");
    inorderTraversal(root);
    printf("\nDeleting 30..");
    delete(root,30);
    printf("\nprint inoder traversal of the BST\n");
    inorderTraversal(root);
    printf("\nDeleting 50..");
    delete(root,50);
    printf("\nprint inoder traversal of the BST\n");
    inorderTraversal(root);
    printf("\nDeleting 200..");
    delete(root,200);
    printf("\nprint inoder traversal of the BST\n");
    inorderTraversal(root);

    
  	printf("\n");
    return 0;
}
