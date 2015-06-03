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
void inorderTraversal(Node *root){
	if(root){
		inorderTraversal(root->lc);
		printf("%d ",root->data);
		inorderTraversal(root->rc);
	}
}
int inorderSucc(Node *root, int data){
	//printf("\nSearching for %d ",root->data);
	
	int succ = -1;
	while(root){
	if(root->data == data){
		if(root->rc){
		Node *t = root->rc;
		for(;t->lc != NULL; t=t->lc);
		return t->data;
		}
		//return root->data;
		}
		
		if(data < root->data){
		succ = root->data;
		root = root->lc;
		}
		else if(data > root->data){
		root = root->rc;
		}
		else
		break;
	}
	return succ;
/*	if(data < root->data)
		inorderSucc(root->lc,data);
	else
		inorderSucc(root->rc,data);
		return -1;
*/
}

int inorderPredessor(Node *root, int data){
	int pred = -1;
	
	while(root){
		if(root->data == data){
			if(root->lc){
			Node *temp = root->lc;
			for(;temp->rc != NULL; temp=temp->rc);
			return temp->data;
			}
		}
		
		if(data < root->data){
			root = root->lc;
		}else if(data > root->data){
			pred = root->data;
			root = root->rc;
		}else
		break;
	}
	return pred;
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
    
    printf("\nInorder predessor of 40 is %d",inorderPredessor(root,40));
    printf("\n");
    printf("\nInorder predessor of 80 is %d",inorderPredessor(root,80));
    printf("\n");
    printf("\nInorder predessor of 50 is %d",inorderPredessor(root,50));
    printf("\n");
    printf("\nInorder predessor of 30 is %d",inorderPredessor(root,30));
    printf("\n");
    printf("\nInorder predessor of 20 is %d",inorderPredessor(root,20));
    printf("\n");
    printf("\nInorder predessor of 60 is %d",inorderPredessor(root,60));
    printf("\n");
    
    printf("\nprint inoder traversal of the BST\n");
    inorderTraversal(root);
    
    printf("\nInorder successor of 40 is %d",inorderSucc(root,40));
    printf("\n");
    printf("\nInorder successor of 80 is %d",inorderSucc(root,80));
    printf("\n");
    printf("\nInorder successor of 50 is %d",inorderSucc(root,50));
    printf("\n");
    printf("\nInorder successor of 30 is %d",inorderSucc(root,30));
    printf("\n");
    printf("\nInorder successor of 20 is %d",inorderSucc(root,20));
    printf("\n");
    printf("\nInorder successor of 60 is %d",inorderSucc(root,60));
    printf("\n");
    
	return 0;
}
