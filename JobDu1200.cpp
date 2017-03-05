#include <stdio.h>
#include <stdlib.h>

#define M 4
#define N 5

int a[M][N], f[M][N];

int n;

int main(){
	int i, j, k, n, tmp;
	while(scanf("%d", &n) != EOF){
		while((n--)){
			for(i = 0; i < M; ++i){
				for(j = 0; j < N; ++j){
					scanf("%d", &a[i][j]);
					f[i][j] = i;
				}
			}

			for(j = 0;j < N; ++j){
				for(i = 0; i < M -1; ++i){
					for(k = 0; k < M -1 -i; ++k){
						if(a[k][j] < a[k+1][j]){
							tmp = a[k][j];
							a[k][j] = a[k+1][j];
							a[k+1][j] = tmp;
							tmp = f[k][j];
							f[k][j] = f[k+1][j];
							f[k+1][j] = tmp;
						}
					}
				}
			}

			for(i = 0;i < 2; ++i){
				for(j = 0;j < N; ++j){
					if(f[0][j] < f[1][j])
						printf("%d ", a[i][j]);
					else
						printf("%d ", a[1-i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}