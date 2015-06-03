#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<vector>

using namespace std;

struct tree{
	int data;
	struct tree *lc;
	struct tree *rc;
};

struct tree * newNode(int d){
	struct tree *node = (struct tree *)malloc(sizeof(struct tree));
	node->data = d;
	node->lc = NULL;
	node->rc = NULL;
	return node;
}
void printVerticalOrderPrint(struct tree *root, int hd, map<int,vector<int> > &m){
	if(root == NULL)
	return;
	m[hd].push_back(root->data);
	printVerticalOrderPrint(root->lc, hd-1,m);
	printVerticalOrderPrint(root->rc, hd+1,m);
}
void printVerticalOrder(struct tree *root){
	map<int , vector<int> > m;
	int horizontalDistance=0;
	printVerticalOrderPrint(root,horizontalDistance,m);
	
	map<int , vector<int> >::iterator it;
	
	for(it=m.begin(); it != m.end();it++){
		int j= it->second.size();
		for(int i=0; i<j; i++){
		cout<<" "<<it->second[i];
		}
		cout<<"\n";
	}
}
int main(){
	typedef struct tree Node;
	Node *root = newNode(1);
    root->lc = newNode(2);
    root->rc = newNode(3);
    root->lc->lc = newNode(4);
    root->lc->rc = newNode(5);
    root->rc->lc = newNode(6);
    root->rc->rc = newNode(7);
    root->rc->lc->rc = newNode(8);
    root->rc->rc->rc = newNode(9);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}
