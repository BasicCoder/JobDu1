#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int graph[1002][1002];
bool vertex[1002];

void bfs(int n){
	queue<int> q;
	vertex[1] = true;
	q.push(1);
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		vertex[tmp] = true;
		for(int i = 1; i <= n; ++i){
			if(graph[tmp][i] && !vertex[i]){
				q.push(i);
			}
		}
	}
}

int main(){
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF && n){
		memset(vertex, 0, sizeof(vertex));
		memset(graph, 0, sizeof(graph));
		int a, b;
		for(int i = 0; i < m; ++i){
			cin >> a >> b;
			graph[a][b] = 1;
			graph[b][a] = 1;
		}

		bfs(n);

		bool find = false;
		for(int i = 1; i <= n; ++i){
			if(!vertex[i]){
				cout << "NO" << endl;
				find = true;
				break;
			}
		}
		if(!find) cout << "YES" << endl;
	}
	return 0;
}