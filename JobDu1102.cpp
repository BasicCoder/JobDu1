#include <stdio.h>
#define INF 0x7fffffff
int Matrix[110][110];
int n, m, k;

int i, j, a, b, c, d;
int main(){
	while(scanf("%d%d%d", &n, &m, &k) != EOF){
		for(i = 1;i <= n; ++i){
			for(j = 1; j <= m; ++j){
				scanf("%d", &Matrix[i][j]);
			}
		}

		int ans = INF;
		for(i = 1; i <= n; ++i){
			for(j = 1; j <= m; ++j){
				for(a = 1; a <= i; ++a){
					for(b = 1; b <= j; ++b){
						int sum = 0;
						int tmp = (i -a+1) * (j -b +1);
						if(tmp > ans)
							continue;
						for( c = a; c <=i; ++c){
							for(d = b; d <=j; ++d){
								sum += Matrix[c][d];
							}
						}
						if(sum >= k && ans > tmp)
							ans = tmp;
					}
				}
			}
		}
		if(ans == INF)
			printf("-1\n");
		else 
			printf("%d\n", ans);

	}
	return 0;
}