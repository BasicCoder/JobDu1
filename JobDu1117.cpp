#include <stdio.h>
#include <stdlib.h>

int a[10], b[10];

int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(){
	int i, t;
	while(scanf("%d", &t) != EOF){
		int k1 = 0, k2 = 0;
		if(t &1){
			b[k2++] = t;
		}else{
			a[k1++] = t;
		}

		for(i = 0; i < 9; ++i){
			scanf("%d", &t);
			if(t&1){
				b[k2++] = t;
			}else{
				a[k1++] = t;
			}
		}

		qsort(a, k1, sizeof(int), cmp);
		qsort(b, k2, sizeof(int), cmp);
		if(k1 == 0){
			for(i = k2 -1; i > 0; --i)
				printf("%d ", b[i]);
			printf("%d\n", b[0]);
		}else{
			for(i = k2 -1; i >= 0; i--)
				printf("%d ", b[i]);
			for(i = 0; i < k1 - 1; ++i){
				printf("%d ", a[i]);
			}
			printf("%d\n", a[k1-1]);
		}
	}
	return 0;
}