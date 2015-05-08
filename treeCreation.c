 
struct tree
{
    int data;
    struct tree* lc;
    struct tree* rc;
};

struct sNode
{
  struct tNode *t;
  struct sNode *next;
};

#include <stdio.h>
#include <stdlib.h>
#include "traversal.h"
#include "traversal.c"


int main()
{
    struct tree *root1 = newNode(1);
    struct tree *root2 = newNode(1);
    root1->lc = newNode(2);
    root1->rc = newNode(3);
    root1->lc->lc  = newNode(4);
    root1->lc->rc = newNode(5); 
 
    root2->lc = newNode(2);
    root2->rc = newNode(3);
    root2->rc->rc = newNode(4);
    root2->rc->rc = newNode(5); 
	
	printf("\nTree size is: %d",treeSize(root1));
	
	printf("\nTree depth is: %d",treeDepth(root1));
	
	printf("\nNumber of leaf node(s): %d",leafCount(root1));
	printf("\nInorder traversal: \n");
	inorderTraversal(root1);
	printf("\nPreorder traversal: \n");
	preorderTraversal(root1);
	printf("\nPostorder traversal: \n");
	postorderTraversal(root1);
		
	printf("\nLevel Order Traversal: \n");
	printLevelOrderTraversal(root1);
	
	struct tree *root = newNode(1);
    root->lc        = newNode(2);
    root->rc       = newNode(3);
    root->lc->lc  = newNode(7);
    root->lc->rc = newNode(6);
    root->rc->lc  = newNode(5);
    root->rc->rc = newNode(4);
	root->lc->lc->lc = newNode(11);
	root->lc->lc->rc = newNode(12);
	root->lc->rc->lc = newNode(13);
	root->lc->rc->rc = newNode(14);
	
	root->rc->lc->lc = newNode(15);
	root->rc->lc->rc = newNode(16);
	root->rc->rc->lc = newNode(17);
	root->rc->rc->rc = newNode(18);
		
	printf("\nLevel Order Traversal In Spiral form : \n");
	printLevelOrderTraversalSpiral(root);
 
 
 
	printf("\nChecking children sum property\n");
	if(isSumProperty(root))
		printf("\nTree follows children sum property\n");
	else
		printf("\nTree does not follow children sum property\n");
	
	struct tree *root3  = newNode(10);
	root3->lc         = newNode(8);
	root3->rc        = newNode(2);
	root3->lc->lc   = newNode(3);
	root3->lc->rc  = newNode(5);
	root3->rc->rc = newNode(2);
	
	printf("\nChecking children sum property for second tree\n");
	if(isSumProperty(root3))
		printf("\nTree follows children sum property\n");
	else
		printf("\nTree does not follow children sum property\n");
	
 
 
	printf("\n\nCreating a binary tree from inorder and preorder traversal:");
	char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
	char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
	printf("\nInorder Traversal of tree: {'D', 'B', 'E', 'A', 'F', 'C'}");
	printf("\nPreorder Traversal of tree: {'A', 'B', 'D', 'E', 'C', 'F'}");
	
	
	int inSize = sizeof(in)/sizeof(in[0]);
	
	struct tree * createdRoot = createTreeeFromTwoTraversals(in, pre, 0, inSize - 1);
	
	printf("\n\nCreated from inorder and preorder traversal:\n");
	inorderCharTraversal(createdRoot);
	
	struct tree *root4 = newNode(1);
    root4->lc = newNode(2);
    root4->rc = newNode(3);
    root4->lc->lc  = newNode(4);
    root4->lc->rc = newNode(5);
	printf("\n\nDoubling the tree :\n");
	inorderTraversal(root4);
	printf("\n\n");
	doubleTree(root4);
	printf("\nAfter doubling the tree is :\n");
	inorderTraversal(root4);
	
	
     if(identicalTrees(root1, root2))
        printf("\nBoth tree are identical");
    else
        printf("\nTrees are not identical");
	printf("\nBoundry traversal of tree :\n");
	struct tree *root5 = newNode(20);
    root5->lc = newNode(8);
    root5->lc->lc = newNode(4);
    root5->lc->rc = newNode(12);
    root5->lc->rc->lc = newNode(10);
    root5->lc->rc->rc  = newNode(14);
    root5->rc = newNode(22);
    root5->rc->rc = newNode(25);
	boundaryTraversal(root5);
	getchar();
	deleteTree(root1);
	deleteTree(root2);
	deleteTree(root3);
	deleteTree(root4);
	deleteTree(root5);
	printf("\n");
	
 
    
  return 0;
}