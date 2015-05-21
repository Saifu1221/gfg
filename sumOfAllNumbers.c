#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<math.h>
//#include "traversal.h"
//#include "traversal.c"
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
void printfArray(int arr[], int *index,int *sum){
	int i;
	printf("\nPath: ");
	for(i =0;i<= *index;i++){
		printf("%d",arr[i]);
		*sum = *sum + arr[i]*pow(10,*index -i);
	}
	//printf("\nSum = %d ",sum );
}

void treePathsSum(struct tree *root, int arr[],int *index,int *sum){
	if(root == NULL)
		return ;
	arr[++(*index)] = root->data;
	
	if(root->lc == NULL && root->rc == NULL){
		printfArray(arr,index,sum);
		(*index)--;
	}
	treePathsSum(root->lc,arr,index,sum);
	
	
	treePathsSum(root->rc,arr,index,sum);
	if(root->lc != NULL && root->rc != NULL){
		//printfArray(arr,index);
		(*index)--;
	}
	
	//(*index)--;
}
int main()
{
    struct tree *root = newNode(6);
	int arr[100],index = -1,sum =0 ;
    root->lc = newNode(3);
    root->rc = newNode(5);
    root->rc->rc = newNode(7);
    root->lc->lc = newNode(2);
    root->lc->rc = newNode(5);
    root->rc->rc = newNode(4);
    root->lc->rc->lc = newNode(7);
    root->lc->rc->rc = newNode(4);
    //printf("Sum of all paths is \n");
	treePathsSum(root,arr,&index,&sum);
	printf("\nSum of all paths is = %d ",sum );

    return 0;
	return 0;
} 
 

