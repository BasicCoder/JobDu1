#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char s[100];
int main(){
	int i, j;
	int a, b, c, d;
	while(scanf("%d", &n) != EOF){
		for(i = 0; i < n; ++i){
			scanf("%d.%d.%d.%d", &a, &b, &c, &d);
			if(0 <= a && a <= 255 && 0 <= b && b <= 255 && 0 <= c && c <= 255 && 0 <= d && d <= 255){
				printf("Yes!\n");
			}else 
				printf("No!\n");
		}
	}
	return 0;
}