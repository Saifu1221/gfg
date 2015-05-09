#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 100
struct Stack{
	int top;
	int Items[SIZE];
};

void push(struct Stack *st, int data){
	if(st->top == SIZE-1){
		printf("\nStack Overflow!!");
		return;
	}
	//printf("\nPushing : %d",data);
	st->Items[++st->top] = data;
}

int pop(struct Stack *st){
	if(st->top == -1){
		printf("\nStack Underflow!!");
		return 0;
	}
	//printf("\nPopping : %d",st->Items[st->top]);
	return st->Items[st->top--];;
}

bool isEmpty(struct Stack * st){
	return st->top == -1;
}
 bool isFull(struct Stack *st){
	 return st->top == SIZE-1;
 }
 
 void printNextGreaterEle(int arr[], int n){
	 int i = 0;
    struct Stack s;
    s.top = -1;
    int element, next;
	 for(i=0; i<n;i++)
		printf("%d ",arr[i]);
	/*while(!isEmpty(&s)){
		printf("\n: %d",pop(&s));
	} */
	push(&s, arr[0]);
	
	for(i=1; i<n; i++){
		next = arr[i];
		if(!isEmpty(&s)){
			element = pop(&s);
				while(next > element){
					printf("\n%d->%d",element,next);
					if(isEmpty(&s))
						break;
					element = pop(&s);
				}
			if(next < element)
				push(&s,element);
			}
			push(&s, next);
		}
		
	
	while(!isEmpty(&s)){
		printf("\n%d->-1",pop(&s));
	}
	
 }
 int main(){
	 //int i,j;
	 int arr[]= {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
	 printNextGreaterEle(arr, n);
	 
 }