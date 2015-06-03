#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
    6
   /   \
  3     5
 / \   / \
7   8 1   3
Say two node be 7 and 1, result is TRUE.
Say two nodes are 3 and 5, result is FALSE.
Say two nodes are 7 and 5, result is FALSE.
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
int level(Node *root, Node *node, int lev){
	//printf("\n4");
	if(root == NULL)
	return 0;
	if(root == node)
	return lev;
	
	int l = level(root->lc, node, lev+1);
	if(l != 0) return l;
	return level(root->rc, node, lev+1);
	//printf("\nRETURNING");
}

bool isSiblings(Node *root, Node *n1, Node *n2){
	//printf("\n3");
	if(root == NULL)
	return 0;
	return (root->lc == n1 && root->rc == n2) || (root->lc == n2 && root->rc == n1) ||
	 (isSiblings(root->lc,n1,n2)) || (isSiblings(root->rc,n1,n2));
}

int isCousin(Node *root, Node *n1, Node *n2){
	//printf("\n2");
	if(level(root,n1,1) == level(root,n2,1) && (!isSiblings(root, n1, n2)))
	return 1;
	else
	return 0;
}

int main()
{
    Node *root = newNode(1);
    root->lc = newNode(2);
    root->rc = newNode(3);
    root->lc->lc = newNode(4);
    root->lc->rc = newNode(5);
    root->lc->rc->rc = newNode(15);
    root->rc->lc = newNode(6);
    root->rc->rc = newNode(7);
    root->rc->lc->rc = newNode(8);
 
    Node *Node1,*Node2;
    Node1 = root->lc->lc;
    Node2 = root->rc->rc;
 	//printf("\n1");
    isCousin(root,Node1,Node2)? puts("Yes"): puts("No");
    //printf("\n100");
 
    return 0;
}
