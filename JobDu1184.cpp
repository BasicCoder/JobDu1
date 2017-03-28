#include <stdio.h>
#include <stdlib.h>

char str[110];
int index = 0;
struct Node{
	char val;
	Node *left;
	Node *right;
};

int CreateTree(Node * &t){
	if(str[index] == '#'){
		t = NULL;
		++index;
	}else{
		t = new Node();
		t -> val = str[index];
		++index;
		CreateTree(t -> left);
		CreateTree(t -> right);
	}
	return 0;
}

void inOrder(Node * t){
	if(t){
		inOrder(t -> left);
		printf("%c ", t -> val);
		inOrder(t -> right);
	}
}

int main(){
	Node *t = NULL;
	while(scanf("%s", str) != EOF){
		index = 0;
		CreateTree(t);
		inOrder(t);
		printf("\n");
	}
	return 0;
}