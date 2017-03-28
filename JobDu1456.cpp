#include <stdio.h>
#include <queue>

using namespace std;

bool mark[50][50][50];
int maze[50][50][50];

struct N{
	int x, y, z;
	int t;
};

queue<N> que;

int go[][3] = {
	1, 0, 0,
	-1, 0, 0,
	0, 1, 0,
	0, -1, 0,
	0, 0, 1,
	0, 0, -1
};

int bfs(int a, int b, int c){
	while(!que.empty()){
		N now = que.front();
		que.pop();
		for(int i = 0; i < 6; ++i){
			int nx = now.x + go[i][0];
			int ny = now.y + go[i][1];
			int nz = now.z + go[i][2];
			if(nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || nz >= c)continue;
			if(maze[nx][ny][nz] == 1) continue;
			if(mark[nx][ny][nz] == true) continue;
			N tmp;
			tmp.x = nx;
			tmp.y = ny;
			tmp.z = nz;
			tmp.t = now.t + 1;
			que.push(tmp);
			mark[nx][ny][nz] = true;
			if(nx == a -1 && ny == b -1 && nz == c -1) return tmp.t;
		}
	}
	return -1;
}

int main(){
	int k;
	scanf("%d", &k);
	while(k--){
		int a, b, c, t;
		scanf("%d%d%d%d", &a, &b, &c, &t);
		for(int i = 0;i < a; ++i){
			for(int j = 0; j < b; ++j){
				for(int m = 0; m < c; ++m){
					scanf("%d", &maze[i][j][m]);
					mark[i][j][m]=false;
				}
			}
		}

		while(!que.empty())que.pop();

		mark[0][0][0] = true;

		N tmp;
		tmp.t = tmp.y = tmp.x = tmp.z = 0;
		que.push(tmp);

		int rec = bfs(a,b,c);
		if(rec <= t) printf("%d\n", rec);
		else printf("-1\n");
	}
	return 0;
}