#include <stdio.h>
#include <stdlib.h>


int max(int a, int b){
	return a > b ? a : b;
}
int n;
int h[101];
int dp1[101];
int dp2[102];

int main(){
	int i;
	while(scanf("%d", &n) != EOF){
		for(i = 1; i <= n; ++i){
			scanf("%d", &h[i]);
		}
		for(i = 1; i <= n; ++i){
			int tmax = 1;
			for(int j = 1; j < i; ++j){
				if(h[j] < h[i]) tmax = max(tmax, dp1[j] + 1);
			}
			dp1[i] = tmax;
		}
		for(i = n; i >= 1; --i){
			int tmax = 1;
			for(int j = n; j > i; --j){
				if(h[j] < h[i]) tmax = max(tmax, dp2[j] + 1);
			}
			dp2[i] = tmax;
		}
		int ans = 1;
		for(int i = 1; i <= n; ++i){
			ans = max(ans, dp1[i] + dp2[i] -1);
		}
		printf("%d\n", n - ans);
	}
	return 0;
}