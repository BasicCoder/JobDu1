#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

char str[10],a[10];
int len;
bool visit[30];

void permuteRecursive(int begin){
	if(begin >= len){
		puts(a);
	}
	for(int i = 0; i < len; ++i){
		if(visit[i] == false){
			visit[i] = true;
			a[begin] = str[i];
			permuteRecursive(begin + 1);
			visit[i] = false;
		}
	}
}

int main(){
	while(scanf("%s", str) != EOF){
		memset(visit, 0, sizeof(visit));
		memset(a, 0, sizeof(a));
		len = strlen(str);
		permuteRecursive(0);
		printf("\n");  
	}
	return 0;
}