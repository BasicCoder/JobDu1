#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int graph[1001][1001];
bool vertex[1001];

void dfs(int i, int n){
	vertex[i] = true;
	for(int j = 1; j <= n; ++j){
		if(graph[i][j] && !vertex[j]){
			dfs(j, n);
		}
	}
	return ;
}

int main(){
	int n, m;
	while(scanf("%d", &n) != EOF && n){
		cin >> m;
		memset(graph, 0, sizeof(graph));
		memset(vertex, 0, sizeof(vertex));
		
		int a,b;
		for(int i = 0; i < m; ++i){
			cin >> a >> b;
			graph[a][b] = 1;
			graph[b][a] = 1;
		}
		int count = 0;
		for(int i = 1; i <= n; ++i){
			if(!vertex[i]){
				++count;
				dfs(i, n);
			}
		}
		cout << count -1 << endl;
	}
	return 0;
}