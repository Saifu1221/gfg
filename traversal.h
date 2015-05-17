<<<<<<< HEAD
#include <stdbool.h>
struct tree * newNode(int);

void inorderTraversal(struct tree *);

void inorderCharTraversal(struct tree *);

void preorderTraversal(struct tree *);

void postorderTraversal(struct tree *tree);

int treeSize(struct tree *);

int treeDepth(struct tree *);

int leafCount(struct tree *);


void push(struct sNode** top_ref, struct tNode *t);
struct tNode *pop(struct sNode** top_ref);
bool isEmpty(struct sNode *top);

bool identicalTrees(struct tree *, struct tree *);

void deleteTree(struct tree *);

//Level Order Traversal
void printLevelOrderTraversal(struct tree *);

void printGivenLevel(struct tree *, int);

//Level Order Traversal Spiral
void printLevelOrderTraversalSpiral(struct tree *);

//void printGivenLevelSpiral(struct tree *, int,int);
void printGivenLevelSpiral(struct tree *, int, int *, int arr[]);

void printArrayInspiralform(int arr[], int size);

bool isSumProperty(struct tree *node);

//Creating a binary tree from inorder and preorder traversal
struct tree * createTreeeFromTwoTraversals(char a[], char b[], int, int);
int search(char a[], int, int, int);

//Double tree
void doubleTree(struct tree *);

void boundaryTraversal(struct tree *);

void printLeavNodes(struct tree *);
=======
#include <stdbool.h>
struct tree * newNode(int);

void inorderTraversal(struct tree *);

void inorderCharTraversal(struct tree *);

void preorderTraversal(struct tree *);

void postorderTraversal(struct tree *tree);

int treeSize(struct tree *);

int treeDepth(struct tree *);

int leafCount(struct tree *);


void push(struct sNode** top_ref, struct tNode *t);
struct tNode *pop(struct sNode** top_ref);
bool isEmpty(struct sNode *top);

bool identicalTrees(struct tree *, struct tree *);

void deleteTree(struct tree *);

//Level Order Traversal
void printLevelOrderTraversal(struct tree *);

void printGivenLevel(struct tree *, int);

//Level Order Traversal Spiral
void printLevelOrderTraversalSpiral(struct tree *);

//void printGivenLevelSpiral(struct tree *, int,int);
void printGivenLevelSpiral(struct tree *, int, int *, int arr[]);

void printArrayInspiralform(int arr[], int size);

bool isSumProperty(struct tree *node);

//Creating a binary tree from inorder and preorder traversal
struct tree * createTreeeFromTwoTraversals(char a[], char b[], int, int);
int search(char a[], int, int, int);

//Double tree
void doubleTree(struct tree *);

void boundaryTraversal(struct tree *);

void printLeavNodes(struct tree *);
>>>>>>> ebd7163620364a794807ec9800895ae678ed329d
