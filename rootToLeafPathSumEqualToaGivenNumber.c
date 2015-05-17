#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
bool printAncestorsIfSums(struct tree *root, int sum,int number){
	if(root == NULL)
	return false;
	sum = sum + root->data;
	if(number == sum){
	printf("\n%d",root->data);
	return true;
	}

	if(printAncestorsIfSums(root->lc,sum,number) || printAncestorsIfSums(root->rc,sum,number)){
		printf("\n%d",root->data);
		//return true;
	}
	
	//return false;
}

int main()
{
    printf("\nPrinting ansestors of whose sum = 4\n");
    struct tree *root1 = newNode(1);
    root1->lc = newNode(2);
    root1->rc = newNode(3);
    root1->lc->lc  = newNode(4);
    root1->lc->rc = newNode(5);

	printAncestorsIfSums(root1,0,4);
	
	printf("\nPrinting ansestors of whose sum = 14\n");
	struct tree *root = newNode(1);
    root->lc = newNode(2);
    root->rc = newNode(3);
    root->lc->lc  = newNode(4);
    root->lc->rc = newNode(5);
    root->lc->lc->lc = newNode(7);
 
    printAncestorsIfSums(root,0,14);

	return 0;
} 
 

