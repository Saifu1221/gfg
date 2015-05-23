#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<iostream>
#include<queue>
using namespace std;
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
int treeHeight(Node *root){
	if(!root)
		return 0;
	queue<Node *> q;
	q.push(root);
	int height = 0;
	
	while(1){
		int nc = q.size();
		if(nc == 0)
			return height;
		height++;
		while(nc > 0){
			Node *p = q.front();
			q.pop();
			if(p->lc)
				q.push(p->lc);
			if(p->rc)
				q.push(p->rc);
			nc--;	
		}
	}
}

int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->lc = newNode(2);
    root->rc = newNode(3);
    root->lc->lc = newNode(4);
    root->lc->rc = newNode(5);
 
    printf("Height of tree is %d",treeHeight(root));
    return 0;
}