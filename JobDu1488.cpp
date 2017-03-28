#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

vector<int> edge[501];
queue<int> q;

int main(){
	int n, m;
	int inDegree[501];
	while(scanf("%d%d", &n, &m) != EOF && n){
		memset(inDegree, 0, sizeof(inDegree));
		for(int i = 0; i < n; ++i)
			edge[i].clear();
		int a, b;
		while(m--){
			scanf("%d%d", &a, &b);
			inDegree[b]++;
			edge[a].push_back(b);
		}

		while(!q.empty())q.pop();
		for(int i = 0; i < n; ++i){
			if(inDegree[i] == 0) q.push(i);
		}
		int cnt = 0;
		while(!q.empty()){
			int nowP = q.front();
			q.pop();
			cnt++;
			for(int i = 0; i < edge[nowP].size(); ++i){
				inDegree[edge[nowP][i]] --;
				if(inDegree[edge[nowP][i]] == 0){
					q.push(edge[nowP][i]);
				}
			}
		}

		if(cnt == n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}