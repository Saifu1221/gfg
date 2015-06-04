#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, pointer to lc child
   and a pointer to rc child */
struct node
{
    int data;
    struct node* lc;
    struct node* rc;
}typedef Node;
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->lc = NULL;
    node->rc = NULL;
 
    return(node);
}
void stroreBstInArr(Node *root, int arr[], int *index){
		if(root == NULL)
		return;
		stroreBstInArr(root->lc,arr,index);
		arr[(*index)++] = root->data;
		stroreBstInArr(root->rc,arr,index);
}
int* mergeArrays(int arr[],  int *index, int arr1[], int m,int arr2[], int n){
	int i = 0,j = 0;
	while(i<m && j<n){
		if(arr1[i] < arr2[j]){
		//printf("\nString ..%d ",);
		arr[(*index)++] = arr1[i++];
		}
		else{
		arr[(*index)++] = arr2[j++];
		}
	}
	while(i<m)
	arr[(*index)++] = arr1[i++];
	
	while(j<n)
	arr[(*index)++] = arr2[j++];
}

Node *mergedArrToBst(int arr[], int start, int end){
	if(start>end)
	return NULL;
	int mid = (start+end)/2;
	Node *root = newNode(arr[mid]);
	
	root->lc = mergedArrToBst(arr,start,mid-1);
	root->rc = mergedArrToBst(arr,mid+1,end);
	
	return root;
}

Node *mergeTrees(Node *root1, Node *root2, int m, int n){
	int arr1[m],arr2[n],arr[m+n],index = 0;
	
	stroreBstInArr(root1,arr1,&index);
	index = 0;
	stroreBstInArr(root2,arr2,&index);
	int i =0;
	printf("\nArr1\n");
	for(i=0;i<m;i++)
	printf("%d ",arr1[i]);
	printf("\nArr2\n");
	for(i=0;i<n;i++)
	printf("%d ",arr2[i]);
	index = 0;
	mergeArrays(arr,&index,arr1,m,arr2,n);
	int s = m+n;
	//s--;
	printf("\nArr\n");
	for(i=0;i<s;i++)
	printf("%d ",arr[i]);
	printf("\n");
	return mergedArrToBst(arr,0,m+n-1);
}
 
// A utility function to print inorder traversal of a given binary tree
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on lc child */
    printInorder(node->lc);
 
    printf("%d ", node->data);
 
    /* now recur on rc child */
    printInorder(node->rc);
}

/* Driver program to test above functions*/
int main()
{
    /* Create following tree as first balanced BST
           100
          /  \
        50    300
       / \
      20  70
    */
    struct node *root1  = newNode(100);
    root1->lc         = newNode(50);
    root1->rc        = newNode(300);
	root1->rc->rc    = newNode(400);
    root1->lc->lc   = newNode(20);
    root1->lc->rc  = newNode(70);
    
	printf ("\nInorder traversal of tree1 \n");
    printInorder(root1); 
    
	/* Create following tree as second balanced BST
            80
           /  \
         40   120
    */
    struct node *root2  = newNode(80);
    root2->lc         = newNode(40);
    root2->rc        = newNode(120);
 
 	printf ("\nInorder traversal of tree2 \n");
    printInorder(root2); 
	
    struct node *mergedTree = mergeTrees(root1, root2, 6, 3);
 
    printf ("Following is Inorder traversal of the merged tree \n");
    printInorder(mergedTree);
 
    printf ("\n");
    return 0;
}
