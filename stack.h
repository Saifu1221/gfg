#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct Stack{
	int top;
	unsigned capacity;
	int *arr;
};

struct Stack * createStack(unsigned);

void push(struct Stack *, int);

int pop(struct Stack *);

int peek(struct Stack *);

bool isEmpty(struct Stack *);

bool isFull(struct Stack *);

void infixToPostfix(char *);

int precedence(char);

bool isOperand(char);

bool isOperator(char);

int operate(int, int , char);

int evaluatePostfix(char *);
