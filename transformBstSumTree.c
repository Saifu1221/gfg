#include<stdio.h>
#include<stdlib.h>
// A BST node
struct Node
{
    int data;
    struct Node *lc, *rc;
};
 
// A utility function to create a new Binary Tree Node
struct Node *newNode(int item)
{
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->lc = temp->rc = NULL;
    return temp;
}
 
// Recursive function to transform a BST to sum tree.
// This function traverses the tree in reverse inorder so
// that we have visited all greater key nodes of the currently
// visited node
void transformTreeUtil2(struct Node *root, int *sum)
{
   // Base case
   if (root == NULL)  return;
 
   // Recur for rc subtree
   transformTreeUtil2(root->rc, sum);
 
   // Update sum
   *sum = *sum + root->data;
 
   // Store old sum in current node
   root->data = *sum - root->data;
 
   // Recur for lc subtree
   transformTreeUtil2(root->lc, sum);
}
 
// A wrapper over transformTreeUtil()
void transformTree(struct Node *root)
{
    int sum = 0; // Initialize sum
    transformTreeUtil(root, &sum);
}
 
// A utility function to print indorder traversal of a
// binary tree
void printInorder(struct Node *root)
{
    if (root == NULL) return;
 
    printInorder(root->lc);
    printf("%d ",root->data);
    printInorder(root->rc);
}
void transformTreeUtil(struct Node *root, int *sum){
	if(root == NULL)
	return;
	transformTreeUtil(root->rc,sum);
		*sum += root->data;
		root->data = *sum-root->data;
	transformTreeUtil(root->lc,sum);

}
// Driver Program to test above functions
int main()
{
    struct Node *root = newNode(11);
    root->lc = newNode(2);
    root->rc = newNode(29);
    root->lc->lc = newNode(1);
    root->lc->rc = newNode(7);
    root->rc->lc = newNode(15);
    root->rc->rc = newNode(40);
    root->rc->rc->lc = newNode(35);
 
    printf("\nInorder Traversal of given tree\n");
    printInorder(root);
 
    transformTree(root);
 
    printf("\n\nInorder Traversal of transformed tree\n");
    printInorder(root);
 
    return 0;
}
