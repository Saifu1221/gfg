#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ALPHABET_SIZE 26

//typedef struct node node; 

struct node{
	int value;
	struct node *children[ALPHABET_SIZE];
}typedef Node;

struct tri{
	int count;
	Node *root;
}typedef tri;

Node *newNode(){
	int i;
	Node *n = (Node *)malloc(sizeof(Node));
	//if(node){
		n->value = 0;
		for(i=0; i<ALPHABET_SIZE; i++)
			n->children[i] = NULL;
	//}
	return n;
}

void initializeTri(tri *t){
	t->count = 0;
	t->root = newNode();
}

void insert(tri *t, char key[]){
	int i,size,index;
	size = strlen(key);
	Node *crawler = t->root;
	t->count++;
	for(i=0; i<size; i++){
		index = key[i]-'a';
		if(crawler->children[index]){
			crawler = crawler->chlidren[index];
		}
		else
			crawler->children[index] = newNode();
	}
	crawler->value = t->count;
	
}
int search(tri *t, char key[] ){
	int size,index,i;
	Node *crawler = t->root;
	size = strlen(key);
	
	for(i=0; i<size; i++){
		index = key[i]-'a';
		if(!crawler->children[index])
			return 0;
		else
			crawler = crawler->chlidren[index];
	}
	return (0 != crawler && crawler->value);
}

int main(){
	char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    char output[][32] = {"Not present in trie", "Present in trie"};
	int i,size;
	trie_t trie;
    initialize(&trie);
	size  = sizeof(keys)/sizeof(keys[0]);
	
	for(i=0; i<size; i++){
		insert(&trie, keys[i]);
	}
	printf("%s --- %s\n", "the", output[search(&trie, "the")] );
    printf("%s --- %s\n", "these", output[search(&trie, "these")] );
    printf("%s --- %s\n", "their", output[search(&trie, "their")] );
    printf("%s --- %s\n", "thaw", output[search(&trie, "thaw")] );
 
    return 0;
	
	
}
