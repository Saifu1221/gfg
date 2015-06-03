#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
              10
           /      \
	     -2        7
         /   \     
	    8     -4  

Given a Binary Tree, find the maximum sum path from a leaf to root. For example, in the following tree, there are three leaf to root paths 8->-2->10, -4->-2->10 and 7->10. The sums of these three paths are 16, 4 and 17 respectively. The maximum of them is 17 and the path for maximum is 7->10.

*/

struct node{
	int data;
	struct node *lc;
	struct node *rc;
}typedef Node;

Node* newNode(int d){
	Node *node = (struct node *)malloc(sizeof(struct node));
	node->data = d;
	node->lc = NULL;
	node->rc = NULL;
	return node;
}
void maxSumPathUtil(Node *root, int *sum, int *ms){
	if(root == NULL)
	return;
	*sum += root->data;
	printf("\nNode Sum is : %d", *sum);
	if(root->lc == NULL && root->rc == NULL){
		if(*ms < *sum)
		*ms = *sum;
		printf("\nSum is : %d", *sum);
		*sum -= root->data;
	}
	maxSumPathUtil(root->lc, sum, ms);
	maxSumPathUtil(root->rc, sum, ms);
	*sum -= root->data;
}
int maxSumPath(Node *root){
	int sum = 0;
	int maxSum = 0;
	maxSumPathUtil(root,&sum,&maxSum);
	return maxSum;
}


int main()
{
    Node *root = NULL;
 
    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->lc = newNode(-2);
    root->rc = newNode(7);
    root->lc->lc = newNode(8);
    root->lc->rc = newNode(-4);
 
    printf ("Following are the nodes on the maximum sum path \n");
    int sum = maxSumPath(root);
    printf ("\nSum of the nodes is %d ", sum);
 
    getchar();
    return 0;
}

