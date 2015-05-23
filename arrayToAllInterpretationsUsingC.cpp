using namespace std;
#include <iostream>
#include <string>
#include<stdio.h>
#include<stdlib.h>
struct node{
	string str;
	struct node *lc;
	struct node *rc;
}typedef Node;
Node * newNode(string s){
	//cout<<"\nCreating node for : "<<s;
	//Node *nn = (struct node *)malloc(sizeof(struct node));
	Node *nn = new Node;
	nn->lc = NULL;
	nn-> rc = NULL;
	nn->str = s;
	//cout<<"\nNode created";
	return nn;
	
}
string getAlpabat(int i){
	//cout<<"\ncame for : "<<i;
	string alphabet[] = {"", "a", "b", "c", "d", "e","f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "v", "z"};
	if(i<=26)
	return alphabet[i];
	return "";
	
}
void printArray(int arr[], int s, int e){
	for(int i=s; i<e; i++)
		printf("%d ",arr[i]);
	
}
Node* creatTreeUtil(int arr[],int arrSize,int start,int d,string s){
	//cout<<"\nInside Utill....";
	//printf("\nAarry is (%d, %d):",start,arrSize);
	//printArray(arr,start,arrSize);
	if(d > 26 || start >= arrSize){
		//cout<<"\nReturning bco d id "<<d;
		return NULL;
	}
	string ds = s + getAlpabat(arr[start]);
	//cout<<"\n String is :"<<ds;
	Node *p = newNode(ds);
	//cout<<"\nNode created";
	if(start<arrSize){
		d = arr[start];
	//cout<<"\ncalling aagain";
	p->lc = creatTreeUtil(arr,arrSize,start+1,d,ds);
	//cout<<"\ncalling left done";
	if(!(start >= arrSize-1)){
		//cout<<"\ncalling right..";
		d = 10*arr[start]+arr[start+1];
		ds = s + getAlpabat(d);
		//cout<<"\nR String is :"<<ds;
		p->rc = creatTreeUtil(arr,arrSize,start+2,d,ds);
	}
	}
	return p;
	
	
}
void printTree(Node *root){
	if(root == NULL){
		return;
	}
	if(root->lc == NULL && root->lc == NULL)
	cout<<"\n"<<root->str;
	printTree(root->lc);
	
	printTree(root->rc);
	
}

void creatTree(int arr[],int arrSize){
	int stringIndex = 0,start = 0;
	string s="";
	Node *root = creatTreeUtil(arr,arrSize,stringIndex,start,s);
	printf("\nThe all possible interpretations are :");
	printTree(root);
}

int main(){
	int arr[] = {1,2,3,4,5};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	printf("\nArray is : \n");
	printArray(arr,0,arrSize);
	
	
	creatTree(arr,arrSize);
	//creatTree(root,arr,arrSize,stringIndex,start,string s);
	
}