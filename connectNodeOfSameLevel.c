#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *lc;
	struct node *rc;
	struct node* nextRight;
}typedef Node;

Node* newNode(int d){
	struct node *node = (struct node *)malloc(sizeof(struct node));
	node->data = d;
	node->lc = NULL;
	node->rc = NULL;
	return node;
}

Node * getNextRight(Node * p){
	Node *temp = p->nextRight;
	
	while(temp){
		if(temp->lc){
		return temp->lc;		
		}
		if(temp->rc){
		return temp->rc;		
		}
		temp = temp->nextRight;
	}
	return NULL;
}
void connectUtil(Node * root){
	if(root == NULL)
	return;
	
	if(root->nextRight)
	connectUtil(root->nextRight);
	
	if(root->lc){
		if(root->rc){
			root->lc->nextRight = root->rc;
			root->rc->nextRight = getNextRight(root);
		}
		else{
			root->lc->nextRight = getNextRight(root);
		}
		
		connectUtil(root->lc);
	
	}else if(root->rc){
		root->rc->nextRight = getNextRight(root);
		connectUtil(root->rc);
	}
	else
	connectUtil(getNextRight(root));
}

void connect(Node * root){
	root->nextRight = NULL;
	connectUtil(root);
}
int main(){
	
    /* Constructed binary tree is
              10
            /   \
          8      2
        /         \
      3            90
    */
    struct node *root = newNode(10);
    root->lc = newNode(8);
    root->rc = newNode(2);
    root->lc->lc = newNode(3);
    root->rc->rc = newNode(90);
 
    // Populates nextrc pointer in all nodes
    connect(root);
    printf("Following are populated nextRight pointers in the tree "
           "(-1 is printed if there is no nextRight) \n");
    printf("nextRight of %d is %d \n", root->data,root->nextRight? root->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->lc->data,root->lc->nextRight? root->lc->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->lc->data,root->lc->nextRight? root->lc->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->lc->lc->data,root->lc->lc->nextRight? root->lc->lc->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->lc->lc->data,root->lc->lc->nextRight? root->lc->lc->nextRight->data: -1);
 
    getchar();
    return 0;
}
