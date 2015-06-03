#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
	int data;
	struct node *lc,*rc;
}typedef Node;
struct stack{
	Node *node;
	struct stack *next;
}typedef Stack;

bool isEmpty(Stack *s){
	return s == NULL ? true : false;
}

void push(Stack **s, Node *node){
	if(*s == NULL){
		Stack *temp = (Stack *)malloc(sizeof(Stack));
		temp->next = NULL;
		temp->node = node;
		*s = temp;
		return;
	}
	Stack *temp = (Stack *)malloc(sizeof(Stack));
	temp->node = node;
	temp->next = *s;
	*s = temp;
		//printf("\npushing %d ",(temp->node)->data);
}

Node * pop(Stack **s){
	if(isEmpty(*s)){
	printf("\nStack Underflow!");
	return NULL;
	}
	Stack *t = *s;
	Node *n = t->node;
	*s = (*s)->next;
	free(t);
	//printf("\npopping %d ",n->data);
	return n;	
}

Node * newNode(int data){
	Node *nn = (Node *)malloc(sizeof(Node));
	nn->lc = NULL;
	nn->rc = NULL;
	nn->data = data;
	return nn;

}
Node* insert(Node *root, int data){
	//printf("\nINSERTING %d ",data);
	if(root == NULL){
		return newNode(data);
	}
	Node *prev = NULL, *root_ref = root;
	while(root){
		prev = root;
		if(data < root->data)
		root = root->lc;
		else//if(data > root->data)
		root = root->rc;
	}
	if(data <= prev->data)
		prev->lc = newNode(data);
	else
		prev->rc = newNode(data);
	return root_ref;
	
}

void inorderTraversal(Node *root, int k){
	if(root == NULL){
		printf("\nNOthing to print");
		return;
	}
	Stack *s = NULL;
	Node *t = root;
	
	while(t){
	push(&s,t);
	t = t->lc;
	}
	k++;
	while(!isEmpty(s)){
		if(!--k){
			printf("%d ",t->data);
			return;
		}
		t = pop(&s);
		//printf("%d ",t->data);
		
		if(t->rc){
			Node *p = t->rc;
			while(p){
			push(&s,p);
			p = p->lc;
			}
		}
	}
	printf("There isn't such element!");
}
void inorderTraversal2(Node *root){
	static int i=1;
	//printf("\n%d ",i++);
	
	if(root){
	//printf("\n%d ",i++);
		inorderTraversal2(root->lc);
		printf("%d ",root->data);
		inorderTraversal2(root->rc);
	}
}
int main(){
	Node *root = NULL;
	int ele[] = { 20, 8, 22, 4, 12, 10, 14 };
	int i=0;
	for(; i<7;i++)
	root = insert(root,ele[i]); 
	/*
	Stack *s=NULL;
	push(&s,newNode(1));
	push(&s,newNode(2));
	push(&s,newNode(3));
	push(&s,newNode(4));
	
	while(!isEmpty(s))
	printf("%d ",(pop(&s))->data);
	*/
	printf("\ninorder traversal..\n");
	inorderTraversal2(root);
	printf("\n4th smallest elemet is..\n");
	inorderTraversal(root,4);
	printf("\n6th smallest elemet is..\n");
	inorderTraversal(root,6);
	printf("\n10th smallest elemet is..\n");
	inorderTraversal(root,10);
	printf("\n");
	return 0;
}
