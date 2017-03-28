#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;


int map[55][55][55];
int dir[6][3] = {0, 0, 1, 0, 0, -1, 0, 1, 0, 0, -1, 0, 1, 0, 0, -1, 0, 0};

struct Maze{
	int x, y, z;
	int step;
};

Maze r, s, t;

int a, b, c, T;

int bfs(int x, int y, int z){
	queue<Maze> q;
	r.x = x;
	r.y = y;
	r.z = z;
	r.step = 0;
	q.push(r);
	map[x][y][z] = 1;
	while(!q.empty()){
		s = q.front();
		q.pop();
		for(int i = 0; i < 6; ++i){
			t.x = s.x + dir[i][0];
			t.y = s.y + dir[i][1];
			t.z = s.z + dir[i][2];
			t.step = s.step + 1;
			if(t.x >= 0 && t.x < a && t.y >= 0 && t.y < b && t.z >= 0 && t.z < c && map[t.x][t.y][t.z] == 0){
				if(t.x == a -1 && t.y == b -1 && t.z == c -1 && t.step <= T){
					return t.step;
				}else{
					map[t.x][t.y][t.z] = 1;
					q.push(t);
				}
			}
		}
	}
	return -1;
}

int main(){
	int k;
	scanf("%d", &k);
	while(k--){
		scanf("%d%d%d%d", &a, &b, &c, &T);
		for(int i = 0; i < a; ++i){
			for(int j = 0; j < b; ++j){
				for(int m = 0; m < c; ++m){
					scanf("%d", &map[i][j][m]);
				}
			}
		}
		int ans = bfs(0, 0, 0);
		printf("%d\n", ans);
	}
}
