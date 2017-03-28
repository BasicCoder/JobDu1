#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int max(int a, int b){
	return a > b ? a : b;
}
int dp[101][101];
char s1[101], s2[101];

int main(){
	while(scanf("%s%s", s1, s2) != EOF){
		memset(dp, 0, sizeof(dp));
		int len1 = strlen(s1);
		int len2 = strlen(s2);

		for(int i = 1; i <= len1; ++i){
			for(int j = 1; j <= len2; ++j){
				if(s1[i-1] != s2[j-1])
					dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
				else
					dp[i][j] = dp[i-1][j-1] +1;
			}
		}
		printf("%d\n", dp[len1][len2]);
	}
	return 0;
}