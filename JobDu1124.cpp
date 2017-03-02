#include <stdio.h>
#include <string.h>

int main(){
	char a[100000];
	while(scanf("%s", a) != EOF){
		if(strcmp(a, "0") == 0) break;
		int n = 0;
		for(int i = 0; a[i]!='\0'; ++i)
			n += (a[i] - '0');
		int s = n;
		while(n > 9){
			s = 0;
			while(n){
				s += n % 10;
				n /= 10;
			}
			n = s;
		}
		printf("%d\n", n);
	}
	return 0;
}