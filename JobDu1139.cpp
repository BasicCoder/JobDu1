#include <stdio.h>
#include <stdlib.h>

#define MAX 110

int MaxSubMatrix(int *a, int n){
	int max, dp[MAX], i;
	max = a[0];
	dp[0] = a[0];
	for(i = 1; i < n; ++i){
		dp[i] = (dp[i-1] + a[i]) > a[i] ? (dp[i-1] + a[i]) : a[i];
		if(dp[i] > max)
			max = dp[i];
	}
	return max;
}
int main(){
	int n, matrix[MAX][MAX], dp[MAX], sum, max;

	int i, j, k;
	while(scanf("%d", &n) != EOF){
		for(i = 0; i < n; ++i){
			for(j = 0;j < n; ++j){
				scanf("%d", &matrix[i][j]);
			}
		}

		max = matrix[0][0];
		for(i = 0; i < n; ++i){
			for(j = 0; j < n; ++j){
				dp[j] = 0;
			}
			for(j = i; j < n; ++j){
				for(k = 0; k < n; ++k)
					dp[k] += matrix[j][k];

				sum = MaxSubMatrix(dp, n);
				if(sum > max)
					max = sum;
			}
		}
		printf("%d\n", max);
	}
	return 0;
}