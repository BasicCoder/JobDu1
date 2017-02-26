#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

int count_ele(int n){
	int count = 0; 
	while((n & 1) == 0){
		++count;
		n >>= 1;
	}
	return count;
}

int count_zero(int n, int m){
	int count = 0;
	for(int i = n; i >= n -m +1; --i){
		count += count_ele(i);
	}
	return count;
}

int main(){
	int n,m;
	while(scanf("%d%d", &n, &m) != EOF && n){
		cout << count_zero(n, m) << endl;
	}
	return 0;
}