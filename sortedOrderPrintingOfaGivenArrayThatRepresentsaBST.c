#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
    /* Let us create following BST
              4
           /     \
          2      5
         / \    
        1   3       */
void printSorted(int arr[], int start, int end){
	if(start > end)
	return;
	
	printSorted(arr,2*start+1,end);
	printf("%d ",arr[start]);
	printSorted(arr,2*start+2,end);
	
}
int main()
{
  int arr[] = {4, 2, 5, 1, 3};
  int arr_size = sizeof(arr)/sizeof(int);
  printSorted(arr, 0, arr_size-1);
  getchar();
  return 0;
}
