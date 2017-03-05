#include <stdio.h>
#include <stdlib.h>

int matrix[102][102];

int m,n;

int main(){
	int i, j, k, p;
	while(scanf("%d %d", &m, &n) != EOF){
		for(i = 0; i < m; ++i){
			k = 0;
			p = 0;
			for(j = 0; j < n; ++j){
				scanf("%d", &matrix[i][j]);
				p += matrix[i][j];
				if(matrix[i][j] > matrix[i][k]){
					k = j;
				}
			}
			matrix[i][k] = p;
		}

		for(i = 0; i < m; ++i){
			for(j = 0; j < n; ++j){
				printf("%d", matrix[i][j]);
				if(j == n -1){
					printf("\n");
				}else{
					printf(" ");
				}
			}
		}
	}
}