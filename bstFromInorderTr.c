#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
typedef struct Node{
    int data;
    struct Node *lc, *rc;
} Node;

typedef struct Stack{
	int top;
	int capacity;
	Node* *arr;
} Stack;

Stack * createStack(int c){
	printf("\nconstructing stack: \n");
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->capacity = c;
	s->top = -1;
	s->arr = (Node **)malloc(sizeof(Node *)*c);
	printf("\nStack created: \n");
	return s;
}

bool isFull(Stack *s){
	return s->top == s->capacity-1; 
}

bool isEmpty(Stack *s){
	return s->top == -1;
}
Node * peek(Stack *s){
	if(!isEmpty(s))
	return s->arr[s->top];
}
void push(Stack *s,Node *node){
	printf("\npushing %d ",node->data);
	if(isFull(s)){
	printf("\nStack overflow!\n");
	return;
	}
	s->arr[++(s->top)] = node;
}

Node * pop(Stack *s){
	//printf("\npopping %d ",node->data);
	if(isEmpty(s)){
	printf("\nStack underflow!\n");
	return NULL;
	}
	printf("\npopping %d ",(s->arr[(s->top)])->data);
	return s->arr[(s->top)--];
}
Node * newNode(int d){
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->lc = NULL;
	tmp->rc = NULL;
	
	tmp->data = d;
	return tmp;
}
Node * constructTree(int arr[], int n){
	printf("constructing tree: \n");
	Stack *s = createStack(100);
	Node *root = newNode(arr[0]);
	
	push(s,root);
	
	int i = 1;
	Node *t;
	for(; i<n; i++){
		t = NULL;
		printf("\ni : %d",i);
		while(!isEmpty(s) && (peek(s))->data ){
		t = pop(s);
		printf("popped : %d",t->data);
		}
		
		if(t != NULL){
			t->rc = newNode(arr[i]);
			push(s,t->rc);
		}
		if(t == NULL){
		peek(s)->lc = newNode(arr[i]);
		push(s,peek(s)->lc);
		}
	}
	
	return root;

}

void printInorder (Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->lc);
    printf("%d ", node->data);
    printInorder(node->rc);
}
	
int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    Node *root = constructTree(pre, size);
 
    printf("\n\nInorder traversal of the constructed tree: \n");
    printInorder(root);
    printf("\n\n");
 
    return 0;
}


