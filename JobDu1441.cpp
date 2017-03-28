#include <stdio.h>
#include <stdlib.h>

int main(){
	int a,b;
	while(scanf("%d%d", &a, &b) !=EOF && a){
		int ans = 1;

		while(b){
			if(b&1){
				ans *= a;
				ans %= 1000;
			}
			b /= 2;
			a *= a;
			a %= 1000;
		}
		printf("%d\n", ans);
	}
	return 0;
}