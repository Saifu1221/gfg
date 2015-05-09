
#include "stack.h"
int main(){
	/* struct Stack *st = createStack(100);
	push(st,1);
	push(st,2);
	push(st,3);
	push(st,4);
	push(st,5);
	printf("\nStack is :\n");
	while(!isEmpty(st)){
		printf(" %d",pop(st));
	} */
	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
	printf("\nInfix expression is :\n");
	printf("\n%s",exp);
	
    infixToPostfix(exp);
	
	char exp2[] = "231*+9-";
    printf ("\n\nValue of %s is %d", exp2, evaluatePostfix(exp2));
    

}