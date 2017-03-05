#include <stdio.h>
#include <stdlib.h>

int num;

int main(){
	while(scanf("%d", &num) != EOF){
		int c = 0;
		int i = 2;
		int N = num;
		while(i * i <= N){
			if(num % i == 0){
				num /= i;
				++c;
			}else{
				i++;
			}
		}
		if(num != 1)
			++c;
		printf("%d\n", c);
	}
	return 0;
}