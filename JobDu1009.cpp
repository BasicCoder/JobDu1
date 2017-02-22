#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

void InsertNode(TreeNode *&p, int val){
	if(p == NULL){
		p = new TreeNode(val);
		return ;
	}
	if( val < p -> val){
		InsertNode(p -> left, val);
	}else{
		InsertNode(p -> right, val);
	}

}

TreeNode *CreateTree(string& s){
	TreeNode *root = NULL;
	int length = s.length();
	for(int i = 0; i < length; ++i){
		InsertNode(root, s[i] - '0');
	}

	return root;
}


bool TreeCmp(TreeNode *r1, TreeNode * r2){
	if(r1 && r2){
		if(r1 -> val != r2 -> val) return false;
		return TreeCmp(r1 -> left, r2 -> left);
		return TreeCmp(r1 -> right,r2 -> right);
	}else if( !r1 && !r2) return true;
	else return false;
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF && n){
		string s;
		cin >> s;
		TreeNode *root = CreateTree(s);
		for(int i = 0; i < n; ++i){
			string str;
			cin >> str;
			TreeNode *strTree = CreateTree(str);
			bool temp = TreeCmp(root, strTree);
			if(temp) cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}