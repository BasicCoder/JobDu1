#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

long long s[1000001];
long long dp[1000001];
int n;

int main(){
	int i;
	while(scanf("%d", &n) != EOF){
		memset(s, 0, sizeof(s));
		memset(s, 0, sizeof(dp));

		for(i = 0; i < n; ++i){
			scanf("%lld", &s[i]);
		}
		dp[0] = s[0];
		
		long long max_num = dp[0];
		for(i = 1; i <n; ++i){
			dp[i] = max(dp[i-1] + s[i], s[i]);
			if(dp[i] > max_num){
				max_num = dp[i];
			}
		}

		/*for(i = 1; i < n; ++i){
			if(dp[i] > max_num){
				max_num = dp[i];
			}
		}*/
		printf("%lld\n",max_num);

	}
	return 0;
}