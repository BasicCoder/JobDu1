#include <stdio.h>
#include <string.h>

char a[1010];
char b[1010];
int sum[1010];

int main(){
	int i,j, k;
	int len1, len2;
	while(scanf("%s %s", a, b) != EOF){
		memset(sum, 0, sizeof(sum));
		len1 = strlen(a);
		len2 = strlen(b);
		i = len1 - 1;
		j = len2 - 1;
		k = 0;
		int flag = 0;
		while(i >= 0 && j >= 0){
			int tmp = a[i] - '0' + b[j] - '0' + flag;
			sum[k++] = tmp % 10;
			flag = tmp / 10;
			--i;
			--j;
		}
		while(i >= 0){
			int tmp = a[i] - '0' + flag;
			sum[k++] = tmp % 10;
			flag = tmp / 10;
			--i;
		}
		while(j >= 0){
			int tmp = b[j] - '0' + flag;
			sum[k++] = tmp % 10;
			flag = tmp / 10;
			--j;
		}
		while(flag){
			sum[k++] = flag %10;
			flag /= 10;
		}
		for(i = k -1; i >= 0; --i){
			printf("%d", sum[i]);
		}
		printf("\n");
	}
}
