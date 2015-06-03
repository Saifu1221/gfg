#include<stdlib.h>
#include<stdio.h>
struct node{
	int data;
	struct node *lc,*rc;
}typedef Node;

Node * newNode(int d){
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->lc = NULL;
	tmp->rc = NULL;
	tmp->data = d;
	return tmp;
}
int findLastSmaller(int arr[], int first, int last, int cut){
	if(last < first || arr[first] > cut){
		return first - 1;
	}
	
	int low = first;
	int high = last;
	
	while(low < high && arr[high] > cut){
	
		int mid = low + (high-low+1)/2;
		//printf("\nMid is %d ",mid);
		if(arr[mid] > cut)
		high = mid -1;
		else
		low = mid;
	
	}
	return high;
}
void postOrderTraverse(Node *root){
	if(root == NULL)
	return;
	postOrderTraverse(root->lc);
	postOrderTraverse(root->rc);
	printf("%d.. ",root->data);
}
Node * craeteBSTUtil(int arr[], int first, int last){
	if(first == last)
	return newNode(arr[first]);
	if(first > last )
	return NULL;
	
	Node *root = newNode(arr[last]);
	
	int lastSmall = findLastSmaller(arr,first,last-1,arr[last]);
	//printf("\n lastSmall : %d",lastSmall);
	root->lc = craeteBSTUtil(arr,first,lastSmall);
	
	root->rc = craeteBSTUtil(arr,lastSmall+1,last-1);
	
	return root;
	
}
Node * craeteBST(int arr[],int s){
	
	return craeteBSTUtil(arr,0,s-1);
}

int main(){
	int arr[] = {1,7,5,50,40,10};
			  //{0,1,2, 3, 4,5 , 6, 7, 8,9}
	//printf("\n %d \n",findLastSmaller(arr,4,8,2));
	int s = sizeof(arr) / sizeof(arr[0]);
	printf("\ns is %d ",s);
	Node *root = craeteBST(arr,s);
	printf("\nPost order traversal of tree is :");
	postOrderTraverse(root);
	printf("\n");	
	return 0;
	
}
