#include <stdio.h>

int n, a;
int i;
int main(){
	while(scanf("%d", &n) != EOF){
		int c = 0;
		for(i = 0; i < n; ++i){
			scanf("%d", &a);
			if(a&1){
				++c;
			}else{
				--c;
			}
		}
		if(c >= 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}