#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 1010
int n;
char a[100][MAX];

int cmp(const void *a, const void *b){
	int len1 = strlen((char *)a);
	int len2 = strlen((char *)b);
	if(len1 == len2){
		return strcmp((char *)a, (char *)b);
	}else{
		return len1 - len2;
	}
}
int main(){
	int i = 0;
	while(scanf("%d", &n) != EOF){
		for(i = 0; i < n; ++i){
			scanf("%s", a[i]);
		}
		qsort(a, n, sizeof(a[0]), cmp);

		for(i = 0; i < n; ++i){
			cout << a[i] << endl;
		}
	}
	return 0;
}