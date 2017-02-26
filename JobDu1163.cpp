#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

bool list[10001];
bool isPrime(int n){
	if(n == 2) return true;
	for(int i = 2; i <= (int)sqrt((double)n) +1; ++i){
		if(n % i == 0)return false;
	}
	return true;
}
int main(){
	int n;
	memset(list, 0, sizeof(list));
	for(int i = 2; i <= 10000; ++i){
		if(i % 10 == 1){
			if(isPrime(i)){
				list[i] = true;
			}
		}
	}
	while(scanf("%d", &n) != EOF){
		vector<int> ret;
		for(int i = 2; i < n; ++i){
			if(list[i]) ret.push_back(i);
		}
		if(ret.empty()){
			cout <<  -1 << endl;
		}else{
			int size = ret.size();
			for(int i = 0; i < size -1; ++i){
				cout << ret[i] << ' ';
			}
			cout << ret[size -1] << endl;
		}

	}
	return 0;
}