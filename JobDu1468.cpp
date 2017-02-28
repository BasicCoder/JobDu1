#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct Node{
	char c;
	int next;
};

Node nodes[100000];

int getLength(int p){
	int len = 0;
	while(p != -1){
		p = nodes[p].next;
		++len;
	}
	return len;
}

int main(){
	int p1, p2, n;
	while(scanf("%d%d%d",&p1, &p2, &n) != EOF && n){
		int a;
		for(int i = 0; i < n; ++i){
			cin >> a;
			cin >> nodes[a].c >> nodes[a].next;
		}

		int len1 = getLength(p1);
		int len2 = getLength(p2);

		if(len1 > len2){
			int m = len1 - len2;
			while(m){
				p1 = nodes[p1].next;
				--m;
			}
		}else if(len1 < len2){
			int m = len2 - len1;
			while(m){
				p2 = nodes[p2].next;
				--m;
			}
		}
		while(p1 != -1 && p2 != -1 && p1 != p2){
			p1 = nodes[p1].next;
			p2 = nodes[p2].next;

		}

		if(p1 != -1 && p2 != -1 && nodes[p1].c == nodes[p2].c){
			printf("%05d\n", p1);
		}else{
			cout << -1 << endl;
		}

	}
	return 0;
}