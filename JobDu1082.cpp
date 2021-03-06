#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int n, m;

char proxy[1000][16];
char server[5000][16];

int main(){
	int i;
	int result, max, index, flag, start;
	while(scanf("%d", &n) != EOF){
		for(i = 0; i < n; ++i)
			scanf("%s", proxy[i]);

		scanf("%d", &m);
		for(i = 0; i < m; ++i)
			scanf("%s", server[i]);

		if(n == 1){
			for(i = 0; i <m && strcmp(proxy[0], server[i]) != 0; ++i)
				continue;
			if(i < m) printf("-1\n");
			else printf("0\n");
		}else{
			flag = 1;
			result = start = 0;
			while(flag){
				max = -1;
				flag = 0;
				for(i = 0; i < n; ++i){
					index = start;
					while(index < m && strcmp(proxy[i], server[index]) != 0)
						++index;
					if(index > max)
						max = index;
				}
				if(max != m){
					flag = 1;
					++result;
				}
				start = max + 1;
			}
			printf("%d\n", result);
		}
	}
	return 0;
}