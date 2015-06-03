#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 
/* Link list node */
struct node
{
    int data;
    struct node* next;
}typedef Node;
 
 void push (struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* A utility function to print a linked list*/
void printList (struct node *node)
{
    while (node != NULL)
    {
        printf ("%d ", node->data);
        node = node->next;
    }
}
bool isPresent (struct node *head, int data)
{
    struct node *t = head;
    while (t != NULL)
    {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}
Node * getUnion(Node *h1, Node * h2){
	
	//if(h1)
	Node *un = NULL;
	while(h1){
		push(&un, h1->data);
		h1 = h1->next;
	}
	
	while(h2){
		if(!isPresent(un,h2->data))
		push(&un, h2->data);
		h2 = h2->next;
	}
	return un;
} 

Node * getIntersection(Node *h1, Node * h2){
	Node *inter = NULL;
	while(h1){
		while(h2){
			if(isPresent(h1,h2->data)){
			push(&inter,h2->data);
			}
			h2 = h2->next;
		}
		h1 = h1->next;
	}
	return inter;
}
/* A utilty function that returns true if data is present in linked list
else return false */

 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* intersecn = NULL;
    struct node* unin = NULL;
 
    /*create a linked lits 10->15->5->20 */
    push (&head1, 20);
    push (&head1, 4);
    push (&head1, 15);
    push (&head1, 10);
 
    /*create a linked lits 8->4->2->10 */
    push (&head2, 10);
    push (&head2, 2);
    push (&head2, 4);
    push (&head2, 8);
 
    intersecn = getIntersection (head1, head2);
    unin = getUnion (head1, head2);
 
    printf ("\n First list is \n");
    printList (head1);
 
    printf ("\n Second list is \n");
    printList (head2);
 
    printf ("\n Intersection list is \n");
    printList (intersecn);
 
    printf ("\n Union list is \n");
    printList (unin);
 
    return 0;
}

