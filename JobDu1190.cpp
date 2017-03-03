#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 1010
int n;
char a[100][MAX];

bool cmp(char a[], char b[]){
	int len1 = strlen(a);
	int len2 = strlen(b);
	if(len1 == len2){
		return a < b;
	}else{
		return len1 < len2;
	}
}
int main(){
	int i = 0;
	while(scanf("%d", &n) != EOF){
		for(i = 0; i < n; ++i){
			gets(a[i]);
		}
		sort(a, a+n, cmp);

		for(i = 0; i < n; ++i){
			cout << a[i] << endl;
		}
	}
}