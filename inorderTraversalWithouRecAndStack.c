#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "traversal.h"
//#include "traversal.c"
struct tree
{
    int data;
    struct tree* lc;
    struct tree* rc;
}typedef Node;

struct tree * newNode(int d){
	struct tree *node = (struct tree *)malloc(sizeof(struct tree));
	node->data = d;
	node->lc = NULL;
	node->rc = NULL;
	return node;
}
void iorderTraversal(Node *root){
	while(root){
		if(root->lc == NULL){
		printf("%d ",root->data);
		root = root->rc;
		}
		else{
			Node *pre = root->lc;
		
			while(pre->rc != NULL && pre->rc != root){
				pre = pre->rc;
			}
			if(pre->rc == NULL){
				//printf("%d ",pre->data);
				pre->rc = root;
				root = root->lc;
			}
			else{
				pre->rc = NULL;
				printf("%d ",root->data);
				root = root->rc;
			}
		}
	}
}

int main()
{
    printf("\nPrinting ansestors of 5\n");
    struct tree *root = newNode(1);
    root->lc = newNode(2);
    root->rc = newNode(3);
    root->lc->lc  = newNode(4);
    root->lc->rc = newNode(5);
	iorderTraversal(root);
	printf("\n");
	return 0;
}
