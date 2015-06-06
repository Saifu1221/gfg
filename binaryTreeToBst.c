/* A program to convert Binary Tree to Binary Search Tree */
#include<stdio.h>
#include<stdlib.h>
 
/* A binary tree node structure */
struct node
{
    int data;
    struct node *lc;
    struct node *rc;
}typedef Node;
 
 
/* A helper function to count nodes in a Binary Tree */
int countNodes(struct node* root)
{
    if (root == NULL)
     return 0;
    return countNodes (root->lc) +
           countNodes (root->rc) + 1;
}
 
 
/* Utility function to create a new Binary Tree node */
struct node* newNode (int data)
{
    struct node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->lc = NULL;
    temp->rc = NULL;
    return temp;
}
 
/* Utility function to print inorder traversal of Binary Tree */
void printInorder (struct node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on lc child */
    printInorder (node->lc);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
    /* now recur on rc child */
    printInorder (node->rc);
}
void stroreBstInArr(Node *root, int arr[], int *index){
		if(root == NULL)
		return;
		stroreBstInArr(root->lc,arr,index);
		arr[(*index)++] = root->data;
		stroreBstInArr(root->rc,arr,index);
}
void merge(int arr[], int l, int m, int h){
	int n1 = m-l+1;
	int n2 = h-m;
	int L[n1],H[n2];
	int i,j,k=0;
	for(i=0; i<n1;i++)
		L[i]=arr[l+i];
	for(j=0;j<n2; j++)
		H[j] = arr[m+j+1];
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2){
		if(L[i] < H[j])
		arr[k++] = L[i++];
		else
		arr[k++] = H[j++];
	}
	
	while(i<n1)
	arr[k++] = L[i++];
	while(j<n2)
	arr[k++] = H[j++];
}
void sortArray(int arr[], int l, int h){
	if(l<h){
		int m = l + (h-l)/2;
		sortArray(arr,l,m);
		sortArray(arr,m+1,h);
		merge(arr,l,m,h);
	
	}


}

void rebuildBTree(Node *root, int arr[],int *index){
	if(root == NULL)
	return;
	
	rebuildBTree(root->lc,arr,index);
	
	root->data = arr[(*index)++];

	rebuildBTree(root->rc,arr,index);

}
void binaryTreeToBST(Node *root){
	int n = countNodes(root);
	
	int arr[n], index = 0,i;
	stroreBstInArr(root,arr,&index);
	printf("\nStored array is: \n");
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	
	sortArray(arr,0,n-1);
	
	printf("\nSorted array is: \n");
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	index = 0;
	rebuildBTree(root,arr,&index);
	
	
}
 
/* Driver function to test above functions */
int main()
{
    struct node *root = NULL;
 
    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /      \
      20       5   */
    root = newNode(10);
    root->lc = newNode(30);
    root->rc = newNode(15);
    root->lc->lc = newNode(20);
    root->rc->rc = newNode(5);
	
 	printf("\nInorder Traversal of the before convertion: \n");
    printInorder (root);
    
	// convert Binary Tree to BST
    binaryTreeToBST (root);
 
    printf("\nFollowing is Inorder Traversal of the converted BST: \n");
    printInorder (root);
 
 	printf("\n");
    return 0;
}
