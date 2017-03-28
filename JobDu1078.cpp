#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[30];
char str2[30];
struct Node{
	char c;
	Node *left;
	Node *right;
};


Node Tree[50];
int loc;
Node *create(){
	Tree[loc].left = Tree[loc].right = NULL;
	return &Tree[loc++];
}
void postOrder(Node * t){
	if(t -> left != NULL){
		postOrder(t -> left);
	}
	if(t -> right != NULL){
		postOrder(t -> right);
	}
	printf("%c", t -> c);
}

Node * build(int s1, int e1, int s2, int e2){
	Node* ret = create();
	ret -> c = str1[s1];
	int rootIdx;
	for(int i = s2;i <= e2; ++i){
		if(str2[i] == str1[s1]){
			rootIdx = i;
			break;
		}
	}
	if(rootIdx != s2){
		ret -> left = build(s1+1, s1 + (rootIdx -s2),s2,rootIdx -1);
	}
	if(rootIdx != e2){
		ret -> right = build(s1+(rootIdx -s2)+1, e1, rootIdx +1, e2);
	}
	return ret;
}

int main(){
	while(scanf("%s%s", str1, str2) != EOF){
		loc  = 0;
		int l1 = strlen(str1);
		int l2 = strlen(str2);
		Node *t = build(0, l1 -1, 0, l2 -1);
		postOrder(t);
		printf("\n");
	}
	return 0;
}