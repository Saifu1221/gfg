#include "traversal.h"
//Create a new node and return pointer to the node
struct tree * newNode(int d){
	struct tree *node = (struct tree *)malloc(sizeof(struct tree));
	node->data = d;
	node->lc = NULL;
	node->rc = NULL;
	return node;
}

//Inorder traversal
void inorderTraversal(struct tree *tree){
	if(tree == NULL)
		return;
	inorderTraversal(tree->lc);
	printf(" %d",tree->data);
	inorderTraversal(tree->rc);
}
//Inorder Cahr tree traversal
void inorderCharTraversal(struct tree *tree){
	if(tree == NULL)
		return;
	inorderCharTraversal(tree->lc);
	printf(" %c",tree->data);
	inorderCharTraversal(tree->rc);
}
//Preorder traversal
void preorderTraversal(struct tree *tree){
	if(tree == NULL)
		return;
	
	printf(" %d",tree->data);
	
	preorderTraversal(tree->lc);
	
	preorderTraversal(tree->rc);
}
//Postorder traversal
void postorderTraversal(struct tree *tree){
	if(tree == NULL)
		return;
	
	postorderTraversal(tree->lc);
	
	postorderTraversal(tree->rc);
	
	printf(" %d",tree->data);
	
}

//No of nodes in a tree
int treeSize(struct tree *root){
	if(root == NULL)
		return 0;
	return(treeSize(root->lc) + treeSize(root->rc) + 1);
}

//Find the depth of a tree
int treeDepth(struct tree *root){
	if(root == NULL)
		return 0;
	int ld = treeDepth(root->lc);
	int rd = treeDepth(root->rc);
	
	return (ld > rd ? ld+1 : rd+1);
	
}

//Count leaf node in a tree
int leafCount(struct tree *root){
	if(root == NULL)
		return 0;
	if(root->lc == NULL && root->rc == NULL)
		return 1;
	return (leafCount(root->lc) + leafCount(root->rc));
}

//Identify whether two trees are identical or not
bool identicalTrees(struct tree *node1, struct tree *node2){
	if(node1 == NULL && node2 == NULL)
		return true;
	if(node1 !=NULL && node2 != NULL)
		return ((node1->data == node2->data) && (identicalTrees(node1->lc, node2->lc)) && (identicalTrees(node2->lc, node2->lc)));
	return false;
}

//Deleting a tree
void deleteTree(struct tree *node){
	if(node == NULL)
		return;
	deleteTree(node->lc);
	deleteTree(node->rc);
	//printf("\nDeleting node: %d", node->data);
	free(node);
	
}
//Level Order Traversal
void printLevelOrderTraversal(struct tree *node){
	
	int h = treeDepth(node);
	int i;
	for(i = 1; i <= h; i++)
		printGivenLevel(node, i);
}

void printGivenLevel(struct tree *node, int level){
	if(node == NULL)
		return;
	if(level == 1)
		printf("%d ",node->data);
	printGivenLevel(node->lc, level - 1);
	printGivenLevel(node->rc, level - 1);
}


//Level Order Traversal Spiral
void printLevelOrderTraversalSpiral(struct tree *node){
	int h = treeDepth(node);
	int i;
	int arr[100], index = 0;
	for(i = 1; i <= h; i++){
		printGivenLevelSpiral(node, i, &index ,arr);
		printArrayInspiralform(arr,index);
		index = 0;
	}
	
}

void printGivenLevelSpiral(struct tree *node, int level, int *arrSize, int arr[]){
	
		if(node == NULL)
		return;
	if(level == 1)
		arr[(*arrSize)++] = node->data;
	
	printGivenLevelSpiral(node->lc, level - 1,arrSize, arr);
	printGivenLevelSpiral(node->rc, level - 1,arrSize, arr);
}

void printArrayInspiralform(int arr[], int size){
	int i;
	printf("\n Printing .. ");
	for(i=0; i<size/2; i++){
		//if(i%2 == 0)
			printf("%d ",arr[i]);
		//else
			printf("%d ",arr[size - i -1]);
	}
		printf("\n");
}

//check-for-children-sum-property-in-a-binary-tree
bool isSumProperty(struct tree *node){
	if(node == NULL || (node->lc == NULL && node->rc == NULL))
		return true;
	return (node->data == ((node->lc ? node->lc->data : 0 ) + (node->rc ? node->rc->data : 0))) &&(isSumProperty(node->lc)) &&( isSumProperty(node->rc)); 
}

struct tree * createTreeeFromTwoTraversals(char in[], char pre[], int start, int end){
	static int index = 0;
	if(start > end)
		return NULL;
	struct tree *node = newNode(pre[index++]);
	
	if(start == end)
		return node;
	int inIndex = search(in, node->data, start, end);
	
	node->lc = createTreeeFromTwoTraversals(in, pre, start, inIndex - 1);
	
	node->rc = createTreeeFromTwoTraversals(in, pre, inIndex + 1, end);
	
	return node;
	
}

int search(char in[], int data, int start, int end){
		int i;
		for(i = start; i <= end; i++){
			if(in[i] == data)
				return i;
		}
}

void doubleTree(struct tree *node){
	if(node == NULL)
		return;
	doubleTree(node->lc);
	doubleTree(node->rc);
	if(node->lc == NULL){
		struct tree *temp = newNode(node->data);
		node->lc = temp;
	}
	else{
		struct tree *temp = newNode(node->data);
		struct tree *t = node->lc;
		node->lc = temp;
		temp->lc = t;
	}
		
}


void printLeafNodes(struct tree *node){
	if(node == NULL)
		return;
	if(node->lc == NULL && node->rc == NULL)
		printf("%d ",node->data);
		printLeafNodes(node->lc);
		printLeafNodes(node->rc);
}

void boundaryTraversal(struct tree *node){
	
	//printing left boundaries
	struct tree *temp1 =node;

	//struct tree *temp2 =node;

	while(temp1){
		if(temp1->lc != NULL || temp1->rc != NULL)
			printf("%d ",temp1->data);
		temp1 = temp1->lc;
	}
	//printing leaves
	printLeafNodes(node);
	
//printing right boundaries
struct tree *temp2 =node->rc;
	while(temp2){
		if(temp2->lc != NULL || temp2->rc != NULL)// && temp2 != node) 
			printf("%d ",temp2->data);
		temp2 = temp2->rc;
	}
	
}
