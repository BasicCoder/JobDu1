#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int matrix[6][6];
int a, b, x, y;
int i, j;
int mat[6][6];
void Rotation(int x, int y, int n){
	for(i = x; i < x +n; ++i){
		for(j = y; j < y +n; ++j){
			mat[j][i] = matrix[x+n -i][j];
		}
	}
	for(i = x; i < x +n; ++i){
		for(j = y; j < y +n; ++j){
			matrix[i][j] = mat[i][j];
		}
	}
}
int main(){
	while(scanf("%d", &matrix[1][1]) != EOF){
		for(j = 2; j <= 5; ++j)
			scanf("%d", &matrix[1][j]);
		for(i = 2; i <=5; ++i){
			for(j = 1; j <= 5; ++j){
				scanf("%d", &matrix[i][j]);
			}
		}
		scanf("%d %d %d %d", &a, &b, &x, &y);
		
		if(a == 1){
			if(b == 2){
				Rotation(x, y, 2);
			}else if(b == 3){
				Rotation(x, y, 3);
			}
		}else if(a == 2){
			if(b == 2){
				Rotation(x, y, 2);
				Rotation(x, y, 2);
				Rotation(x, y, 2);
			}else if(b == 3){
				Rotation(x, y, 3);
				Rotation(x, y, 3);
				Rotation(x, y, 3);
			}
		}

		for(i = 1; i <= 5; ++i){
			for(j = 1; j <= 5; ++j){
				printf("%d", matrix[i][j]);
				if(j == 5)
					printf("\n");
				else 
					printf(" ");
			}
		}
		
	}
}