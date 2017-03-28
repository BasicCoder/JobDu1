#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

struct E{
	int next;
	int c;
	int cost;
};

vector<E> edge[1001];
int dis[1001];
int Cost[1001];
bool mark[1001];

int main(){
	int n, m;
	int s, t;
	while(scanf("%d%d", &n, &m) != EOF && n){
		for(int i = 1; i <= n; ++i) edge[i].clear();
		int a, b, c, cost;
		while(m--){
			scanf("%d%d%d%d", &a, &b, &c, &cost);
			E tmp;
			tmp.c = c;
			tmp.cost = cost;
			tmp.next = b;
			edge[a].push_back(tmp);
			tmp.next = a;
			edge[b].push_back(tmp);
		}
		scanf("%d%d", &s, &t);
		for(int i = 1; i <= n; ++i){
			dis[i] = -1;
			mark[i] = false;
		}

		dis[s] = 0;
		mark[s] = true;
		int newP = s;
		for(int i = 1; i < n; ++i){
			for(int j = 0; j < edge[newP].size(); ++j){
				int t = edge[newP][j].next;
				int c = edge[newP][j].c;
				int co = edge[newP][j].cost;
				if(mark[t] == true) continue;
				if(dis[t] == -1 || dis[t] > dis[newP] + c || dis[t] == dis[newP] + c && Cost[t] > Cost[newP] + co){
					dis[t] = dis[newP] + c;
					Cost[t] = Cost[newP] + co;
				}
			}
			int min = INT_MAX;
			for(int j = 1; j <= n; ++j){
				if(mark[j] == true) continue;
				if(dis[j] == -1) continue;
				if(dis[j] < min){
					min = dis[j];
					newP = j;
				}
			}
			mark[newP] = true;

		}
		printf("%d %d\n", dis[t], Cost[t]);
		
	}
	return 0;
}