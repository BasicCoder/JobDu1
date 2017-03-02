#include <stdio.h>

int m,n;

int main(){
	int left, right;
	int cnt, num;
	while(scanf("%d%d", &m, &n) != EOF && m){
		cnt = num = 1;
		left = 2 *m;
		right = 2 *m + 1;
		while(right <= n){
			num *= 2;
			cnt += num;
			left *=2;
			right = 2 * right + 1;
		}
		if(left <= n)
			cnt += (n -left +1);
		printf("%d\n", cnt);
	}
}