#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int child[30];

int find(int x, int y){
	int flag = 0, res = -1;
	while(child[x] != -1){
		if(child[x] == y)break;
		x = child[x];
		res++;
	}
	if(child[x] == y){
		return res;
	}else
		return -1;
}

int main(){
	int n,m;
	while(scanf("%d%d", &n, &m) != EOF && n){
			char buf[5];
			int i, j;
			for(i = 0; i < 30; ++i)
				child[i] = -1;
			for(i = 0; i < n; ++i){
				scanf("%s", &buf);
				int tmp1 = buf[0] - 'A';
				if(buf[1] != '-'){
					int tmp2 = buf[1] - 'A';
					child[tmp2] = tmp1;
				}
				if(buf[2] != '-'){
					int tmp3 = buf[2] - 'A';
					child[tmp3] = tmp1;
				}
			}

			for(i = 0; i < m; ++i){
				scanf("%s", buf);
				int tmp1 = buf[0] - 'A';
				int tmp2 = buf[1] - 'A';
				int ans1 = find(tmp1, tmp2);
				int ans2 = find(tmp2, tmp1);
				if(ans1 == -1 && ans2 == -1){
					printf("-\n");
				}else if(ans1 != -1){
					if(ans1 == 0)
						printf("parent\n");
					else{
						for(j = 0;j < ans1; ++j){
							printf("great-");
						}
						printf("grandparent\n");
					}
				}else if(ans2 != -1){
					if(ans2 == 0)
						printf("child\n");
					else{
						for(j = 0;j < ans2; ++j){
							printf("great-");
						}
						printf("grandchild\n");
					}
				}
			}
	}
	return 0;
}