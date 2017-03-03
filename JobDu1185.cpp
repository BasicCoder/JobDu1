#include <stdio.h>
#include <algorithm>

using namespace std;

int a[1010];
int n;
int main(){
	int i;
	while(scanf("%d", &n) != EOF){
		for(i = 0;i < n; ++i){
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		if(n == 1){
			printf("%d\n-1\n", a[n-1]);
		}else{
				printf("%d\n", a[n-1]);
				for(i = 0; i < n-1; ++i){
					printf("%d", a[i]);
					if(i == n -2)
						printf("\n");
					else 
						printf(" ");
				}
		}
	}
	return 0;
}