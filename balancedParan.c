#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 100

struct Stack{
	char data;
	struct Stack *next;
};

char pop(struct Stack **topRef){
	if(*topRef == NULL){
		printf("\nStack Underflow");
		return 'x';
	}
	char data;
	struct Stack *temp = *topRef;
	*topRef = (*topRef)->next;
	data = temp->data;
	free(temp);
	return data;
}
bool isEmpty(struct Stack *st){
	return st == NULL;
}

void push(struct Stack **topRef, char data){
	struct Stack *new = (struct Stack *)malloc(sizeof(struct Stack));
	if(new == NULL){
		printf("\nStack Overflow!!");
		return;
	}
	if(*topRef == NULL){
		new->data = data;
		new->next = NULL;
		*topRef = new;
	}
	else{
		new->data = data;
		new->next = *topRef;
		*topRef = new;
	}
}

int main(){
	struct Stack *st;
	
	push(&st,'A');
	push(&st,'B');
	push(&st,'C');
	push(&st,'D');
	push(&st,'E');
	push(&st,'F');
	
	while(!isEmpty(st)){
		printf("%c ",pop(&st));
	}
return 0;
}