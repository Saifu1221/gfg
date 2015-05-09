
#include "stack.h"
struct Stack * createStack(unsigned capacity){
	struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack ));
	st->capacity = capacity;
	st->top = -1;
	st->arr = (int *)malloc(sizeof(int)*capacity);
	return st;
}

void push(struct Stack *st, int data){
	if(isFull(st)){
		printf("\n\nStack Overflow");
		return;
	}
	st->arr[++st->top] = data;
}

int pop(struct Stack *st){
	if(isEmpty(st)){
		printf("\n\nStack Underflow");
		return -1;
	}
	return st->arr[st->top--];
}
int peek(struct Stack* stack)
{
    return stack->arr[stack->top];
}
bool isEmpty(struct Stack *st){
	return st->top == -1;
}

bool isFull(struct Stack *st){
	return st->top == st->capacity-1;
}

//Infix to postfix

bool isOperand(char ch){
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
bool isOperator(char ch){
	
}
int precedence(char opr){
	switch(opr){
		case '+':
		case '-':
			return 1;
			//break;
		case '*':
		case '/':
			return 2;
			//break;
		case '^':
			return 3;
			//break;
		default:
			return -1;
	}
}
			

void infixToPostfix(char *expr){
	int i,j,k,length;
	length = (int)strlen(expr);
	struct Stack *st = createStack(length);
	char output[length];
	//printf("\n%d length is :",length);
	for(i=0,k=0;i<length; i++){
		if(isOperand(expr[i]))
			output[k++] = expr[i];
		else if(expr[i] == '(')
			push(st,expr[i]);
		else if(expr[i] == ')'){
			while(!isEmpty(st) && peek(st) != '(')
				output[k++] = pop(st);
				if (!isEmpty(st) && peek(st) != '('){
					printf("\nInvalid expression");
					return;
					}
				else 
					pop(st); //removing ( from stack
        }
		else{ //operator encounter
			while(!isEmpty(st) && (precedence(expr[i]) <= precedence(peek(st))))
				output[k++] = pop(st);
			push(st,expr[i]);
		}
	}
	while (!isEmpty(st))
        output[k++] = pop(st );
 
    output[k] = '\0';
    printf( "\nPostfix expression is \n %s", output );
}

int operate(int val1, int val2, char op){

	switch (op){
             case '+': return(val2 + val1);
             case '-': return(val2 - val1);
             case '*': return(val2 * val1);
             case '/': return(val2 / val1);
            }
}

int evaluatePostfix(char *expr){
	int i, j;
	int length = strlen(expr);
	
	struct Stack *st = createStack(length);
	
	for(i = 0; i <= length; i++){
		if(isdigit(expr[i]))
			push(st, expr[i]);
		else{
			int op1 = pop(st);
			int op2 = pop(st);
			int res = operate(op1, op2, expr[i]);
			push(st,res);
		}
	}
	return pop(st);
}