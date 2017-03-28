#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;

char map[21][21];
int ac[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};
bool judge[21][21][1025];
int n, m, T;
struct Maze{
	int x, y;
	int step, Key;
};

Maze r, s, t;
int bfs(int a, int b){
	r.x = a;
	r.y = b;
	r.step = 0;
	r.Key = 0;
	judge[a][b][0] =true;
	queue<Maze> q;
	q.push(r);
	
	while(!q.empty()){
		s = q.front();
		q.pop();

		for(int i = 0; i < 4; ++i){
			t.x = s.x + ac[i][0];
			t.y = s.y + ac[i][1];
			t.step = s.step + 1;
			t.Key = s.Key;
			if(t.x >= 0 && t.x < n && t.y >= 0 && t.y < m && map[t.x][t.y] != '*' && t.step < T && !judge[t.x][t.y][t.Key]){
				if(map[t.x][t.y] == '^')
					return t.step;
				if(map[t.x][t.y] >= 'a' && map[t.x][t.y] <= 'j'){
					int temp = map[t.x][t.y] - 'a';
					if((t.Key & (1 << temp)) == 0)
						t.Key += (1 << temp);
				}
				if(map[t.x][t.y] >= 'A' && map[t.x][t.y] <= 'J'){
					int temp = map[t.x][t.y] - 'A';
					if((t.Key & (1 << temp)) == 0)
						continue;
				}
				judge[t.x][t.y][t.Key] = true;
				q.push(t);
			}
		}
	}
	return -1;
}

int main(){
	while(scanf("%d %d %d", &n, &m, &T) != EOF){
		int x, y;
		for(int i = 0; i < n; ++i){
			scanf("%s", map[i]);
			for(int j = 0; j < m; ++j){
				if(map[i][j] == '@'){
					x = i;
					y = j;
					map[i][j] = '.';
				}
			}
		}
		memset(judge, 0, sizeof(judge));
		printf("%d\n", bfs(x, y));
	}
}