#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int counts[101];
int main(){
	int n;
	while(scanf("%d", &n) != EOF && n){
		int a;
		memset(counts, 0, sizeof(counts));
		for(int i = 0; i < n; ++i){
			cin >> a;
			counts[a]++;
		}
		cin >> a;
		cout << counts[a] << endl;
	}
	return 0;
}