#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXN 1010
char a[10010][MAXN];

struct Node{
	int len;
	int i;
};
Node b[10010];
int cmp(const void * a, const void * b){

	return ((Node *)a) -> len - ((Node *)b) ->len;
}
int n =0;
int main(){
	
	while(scanf("%s", a[n]) != EOF){
		b[n].len = strlen(a[n]);
		b[n].i = n;
		++n;
	}
	qsort(b, n, sizeof(Node), cmp);

	cout << a[b[0].i] << endl;
	int i = 1;
	while(i < n && b[i].len == b[0].len){
		cout << a[b[i].i] << endl;
		++i;
	}

	i = n -2;
	while(i >= 0 && b[i].len == b[n-1].len) --i;

	++i;
	while(i < n -1){
		cout << a[b[i].i] << endl;
		++i;
	}
	cout << a[b[n-1].i] << endl;
	return 0;
}