#include <stdio.h>
#include <stdlib.h>

long long n, y1, y2;
long long a[21];

int main(){
	int i = 1;
	a[1] = 1;
	for(i = 2; i <= 20; ++i){
		a[i] = a[i-1] * i;
	}
	while(scanf("%lld", &n) != EOF){
		y1 = 0;
		y2 = 0;
		for(i = 1; i <=n; ++i){
			if(i & 1){
				y1 += a[i];
			}else{
				y2 += a[i];
			}
		}
		printf("%lld %lld\n", y1, y2);
	}
	return 0;
}