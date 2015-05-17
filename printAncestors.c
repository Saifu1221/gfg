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
};

struct tree * newNode(int d){
	struct tree *node = (struct tree *)malloc(sizeof(struct tree));
	node->data = d;
	node->lc = NULL;
	node->rc = NULL;
	return node;
}
bool printAncestors(struct tree *root, int number){
	if(root == NULL)
	return false;

	if(root->data == number)
	return true;

	if(printAncestors(root->lc,number) || printAncestors(root->rc,number)){
		printf("\n%d",root->data);
		//return true;
	}
	
	//return false;
}

int main()
{
    printf("\nPrinting ansestors of 5\n");
    struct tree *root1 = newNode(1);
    root1->lc = newNode(2);
    root1->rc = newNode(3);
    root1->lc->lc  = newNode(4);
    root1->lc->rc = newNode(5);

	printAncestors(root1,5);
	
	printf("\nPrinting ansestors of 7\n");
	struct tree *root = newNode(1);
    root->lc = newNode(2);
    root->rc = newNode(3);
    root->lc->lc  = newNode(4);
    root->lc->rc = newNode(5);
    root->lc->lc->lc = newNode(7);
 
    printAncestors(root, 7);

	return 0;
} 
 

