#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

struct N{
	int a, b, c;
	int t;
};

queue<N> que;

bool mark[101][101][101];
void AtoB(int &a, int sa, int &b, int sb){
	if(sb - b >= a){
		b += a;
		a = 0;
	}else{
		a -= sb - b;
		b = sb;
	}
}

int BFS(int s, int n, int m){
	while(!que.empty()){

	N now = que.front();
	que.pop();
	int a, b, c;
	a = now.a;
	b = now.b;
	c = now.c;

	AtoB(a,s,b,n);
	if(mark[a][b][c] == false){
		mark[a][b][c] = true;
		N tmp;
		tmp.a = a;
		tmp.b = b;
		tmp.c = c;
		tmp.t = now.t + 1;

		if(a == s / 2 && b == s / 2) return tmp.t;
		if(c == s / 2 && b == s / 2) return tmp.t;
		if(a == s / 2 && c == s / 2) return tmp.t;
		que.push(tmp);

	}

	a = now.a;
	b = now.b;
	c = now.c;
	AtoB(b, n, a, s);
	if(mark[a][b][c] == false){
		mark[a][b][c] = true;
		N tmp;
		tmp.a = a;
		tmp.b = b;
		tmp.c = c;
		tmp.t = now.t + 1;
		
		if(a == s / 2 && b == s / 2) return tmp.t;
		if(c == s / 2 && b == s / 2) return tmp.t;
		if(a == s / 2 && c == s / 2) return tmp.t;
		que.push(tmp);
	}
	a = now.a;
	b = now.b;
	c = now.c;
	AtoB(a,s,c,m);
	if(mark[a][b][c] == false){
		mark[a][b][c] = true;
		N tmp;
		tmp.a = a;
		tmp.b = b;
		tmp.c = c;
		tmp.t = now.t + 1;
		
		if(a == s / 2 && b == s / 2) return tmp.t;
		if(c == s / 2 && b == s / 2) return tmp.t;
		if(a == s / 2 && c == s / 2) return tmp.t;
		que.push(tmp);
	}
	a = now.a;
	b = now.b;
	c = now.c;
	AtoB(c,m,a,s);
	if(mark[a][b][c] == false){
		mark[a][b][c] = true;
		N tmp;
		tmp.a = a;
		tmp.b = b;
		tmp.c = c;
		tmp.t = now.t + 1;
		
		if(a == s / 2 && b == s / 2) return tmp.t;
		if(c == s / 2 && b == s / 2) return tmp.t;
		if(a == s / 2 && c == s / 2) return tmp.t;
		que.push(tmp);
	}

	a = now.a;
	b = now.b;
	c = now.c;
	AtoB(b, n, c, m);
	if(mark[a][b][c] == false){
		mark[a][b][c] = true;
		N tmp;
		tmp.a = a;
		tmp.b = b;
		tmp.c = c;
		tmp.t = now.t + 1;
		
		if(a == s / 2 && b == s / 2) return tmp.t;
		if(c == s / 2 && b == s / 2) return tmp.t;
		if(a == s / 2 && c == s / 2) return tmp.t;
		que.push(tmp);
	}

	a = now.a;
	b = now.b;
	c = now.c;
	AtoB(c, m, b, n);
	if(mark[a][b][c] == false){
		mark[a][b][c] = true;
		N tmp;
		tmp.a = a;
		tmp.b = b;
		tmp.c = c;
		tmp.t = now.t + 1;
		
		if(a == s / 2 && b == s / 2) return tmp.t;
		if(c == s / 2 && b == s / 2) return tmp.t;
		if(a == s / 2 && c == s / 2) return tmp.t;
		que.push(tmp);
	}
}
return -1;
}

int main(){
	int s, n, m;
	while(scanf("%d%d%d", &s, &n, &m) != EOF && s){
		if(s & 1){
			printf("NO\n");
			continue;
		}
		memset(mark, 0, sizeof(mark));
		N tmp;
		tmp.a = s;
		tmp.b = 0;
		tmp.c = 0;
		tmp.t = 0;
		while(!que.empty())que.pop();
		que.push(tmp);
		mark[s][0][0] = true;
		int rec = BFS(s, n, m);
		if(rec == -1)
			printf("NO\n");
		else
			printf("%d\n", rec);
	}
	return 0;
}