#include <iostream>
#include <string>
#include <queue>
using namespace std;
 
// Linked list node
struct ListNode
{
    int data;
    ListNode* next;
};
 
// Binary tree node structure
struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left, *right;
};
 
// Function to insert a node at the beginning of the Linked List
void push(struct ListNode** head_ref, int new_data)
{
    // allocate node and assign data
    struct ListNode* new_node = new ListNode;
    new_node->data = new_data;
 
    // link the old list off the new node
    new_node->next = (*head_ref);
 
    // move the head to point to the new node
    (*head_ref)    = new_node;
}
 
// method to create a new binary tree node from the given data
BinaryTreeNode* newBinaryTreeNode(int data)
{
    BinaryTreeNode *temp = new BinaryTreeNode;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 

void inorderTraversal(BinaryTreeNode* root)
{
    if (root)
    {
        inorderTraversal( root->left );
        cout << root->data << " ";
        inorderTraversal( root->right );
    }
    
}

void printLL(ListNode * head){
	if(head == NULL){
	cout<<"\nNothing to print in LL";
	return;
	}
	cout<<"\nLL is :\n";
	while(head){
	cout<<head->data<<" ";
	head = head->next;
	}

}
 void convertList2Binary(struct ListNode * head, BinaryTreeNode * &root){
 	if(head ==  NULL){
 	root = NULL;
 	return;
 	}
 	
 	queue<BinaryTreeNode *> q;
 	root = newBinaryTreeNode(head->data);
 	q.push(root);
 	head = head->next;
 	while(head){
 		BinaryTreeNode *parent = q.front();
 		q.pop();
 		BinaryTreeNode *leftChild = NULL, *rightChild = NULL;
 		//cout<<"\nPoppedup data "<<parent->data;
 		//if(head->next != NULL){
 		 leftChild = newBinaryTreeNode(head->data);
 		q.push(leftChild);
 		head = head->next;
 		//}
 		
 		if(head != NULL){
 		rightChild = newBinaryTreeNode(head->data);
 		q.push(rightChild);
 		head = head->next;
 		}
 		
 		parent->left = leftChild;
 		parent->right = rightChild;
 		
 	}
 	
 }
 
// Driver program to test above functions
int main()
{
    // create a linked list shown in above diagram
    struct ListNode* head = NULL;
    push(&head, 36);  /* Last node of Linked List */
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10); /* First node of Linked List */
 	printLL(head);
    BinaryTreeNode *root;
    convertList2Binary(head, root);
 
    cout << "\n\nInorder Traversal of the constructed Binary Tree is: \n";
    inorderTraversal(root);
    cout << "\n\n";
    return 0;
}
