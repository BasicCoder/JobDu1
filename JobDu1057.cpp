#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int counts[12];

int main(){
	int N = 20;
	int a, i;
	while(scanf("%d", &a) != EOF){
		memset(counts, 0, sizeof(counts));
		++counts[a];
		for(i = 1; i < N; ++i){
			cin >> a;
			++counts[a];
		}
		int j = 1;
		int max = counts[1];
		for(i = 2; i <= 10; ++i){
			if(counts[i] > max){
				max = counts[i];
				j = i;
			}
		}
		cout << j << endl;
	}
	return 0;
}