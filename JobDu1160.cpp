#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

void dfs(vector<int> apple, int &ret, int next, int m, int n){
	if(next >= n || m < 0) return;

	apple[next]++;
	for(int i = 0; i < n -1; i++){
		if(apple[i] < apple[i+1]) return;
	}
	if(m == 0){
		ret++;
		return;
	}
	dfs(apple, ret, next, m -1, n);
	dfs(apple, ret, next +1, m, n);
}

int main(){
	int t;
	while(scanf("%d", &t) != EOF){
		int m, n;
		for(int i = 0; i < t; ++i){
			cin >> m >> n;
			vector<int> apple(n, 0);
			int ret = 0;
			dfs(apple, ret, 0, m, n);
			cout << ret << endl;
		}
	}
	return 0;
}