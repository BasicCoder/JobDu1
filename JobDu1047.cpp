#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;



int main(){
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n <= 1){
			printf("no\n");
		}else{
			int i = 2;
			int flag = 0;
			for( ;i <= (long long)sqrt(double(n)); ++i){
				if( n % i == 0){
					printf("no\n");
					flag = 1;
					break;
				}
			}
			if(!flag){
				printf("yes\n");
			}
		}
		
	}
	return 0;
}