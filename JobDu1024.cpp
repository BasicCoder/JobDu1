#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int Tree[101];
int findRoot(int x){
	if(Tree[x] == -1) return x;
	else{
		int tmp = findRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}

struct Edge{
	int a, b;
	int cost;
	bool operator <(const Edge &A)const{
		return cost < A.cost;
	}
};

Edge edge[5500];

int main(){
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF && n){
		memset(Tree, -1, sizeof(Tree));

		for(int i = 1; i <= n; ++i){
			scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].cost);
		}

		sort(edge + 1, edge + 1 + n);

		int ans = 0;
		int count = 0;
		for(int i = 1; i <= n; ++i){
			int a = findRoot(edge[i].a);
			int b = findRoot(edge[i].b);
			if(a != b){
				Tree[a] = b;
				++count;
				ans += edge[i].cost;
			}
		}
		if(count == (m -1)){
			cout << ans << endl;
		}else{
			cout << '?' << endl;
		}
	}
	return 0;
}