#include <stdio.h>

#define MOD 10000
int a0, a1, p, q, k;

void Matrix_mul(int p[2][2], int q[2][2]){
	int i, j, k;
	int t[2][2] = {0};
	for(i = 0; i <= 1; ++i)
		for(j = 0; j <= 1; ++j)
			for(k = 0; k <=1; ++k)
				t[i][j] += p[i][k] * q[k][j];

	for(i = 0; i <= 1; ++i)
		for(j = 0; j <= 1; ++j)
			p[i][j] = t[i][j] % MOD;
}

void Matrix_cal(int p[2][2], int n){
	int i,j;
	int t[2][2];
	for(i = 0; i <= 1; ++i)
		for(j = 0; j <= 1; ++j)
			t[i][j] = p[i][j];
	
	if(n == 1)
		return ;
	else if(n & 1){
		Matrix_cal(p, n -1);
		Matrix_mul(p, t);
	}else{
		Matrix_cal(p, n/2);
		Matrix_mul(p, p);
	}
}

int main(){
	
	while(scanf("%d%d%d%d%d", &a0, &a1, &p, &q, &k) != EOF){
		if(k == 0)
			printf("%d\n", a0);
		else if(k == 1)
			printf("%d\n", a1);
		else{
			int matrix[2][2] = {{p % MOD, q % MOD}, {1, 0}};
			Matrix_cal(matrix, k -1);
			printf("%d\n", (a1 * matrix[0][0] + a0 * matrix[0][1]) % MOD);
		}
	}
	return 0;
}