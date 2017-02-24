#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <limits.h>

using namespace std;

int mat[6][6];
bool visited[6][6];
int ret;
int dist[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int cost, int status, int e1, int e2, int s1, int s2){
	int x, y;
	for(int i = 0; i < 4; i++){
		x = s1 + dist[i][0];
		y = s2 + dist[i][1];

		int tmp = status * mat[x][y];
		if(x < 0 || x >=6 || y < 0 || y >=6 || visited[x][y] || tmp + cost > ret){
			continue;
		}
		if(x == e1 && y == e2){
			if(tmp + cost < ret) ret = tmp + cost;
			continue;
		}
		visited[x][y] = true;
		dfs(tmp + cost, tmp % 4 +1, e1, e2, x, y);
		visited[x][y] = false;
	}
}

int main(){
	int n;

	int s1, s2, e1, e2;
	scanf("%d", &n);
	while(n--){
		ret = INT_MAX;
		for(int i = 0; i < 6; ++i){
			for(int j = 0; j < 6; ++j){
				cin >> mat[i][j];
				visited[i][j] = false;
			}
		}

		cin >> s1 >> s2 >> e1 >> e2;
		dfs(0, 1, e1, e2, s1, s2);
		cout << ret << endl;		
	}
}
