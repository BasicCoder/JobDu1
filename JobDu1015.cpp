#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool compare(int a, int b, int k){

	while(k){
		if(a % 10 != b % 10)return false;

		a /= 10;
		b /= 10;
		--k;
	}
	return true;
}

int main(){
	int a, b, k;
	while(scanf("%d%d%d", &a, &b, &k) != EOF){
		if(a == 0 && b == 0)break;

		if(compare(a,b,k))cout << -1 << endl;
		else cout << a + b << endl;
	}
	return 0;
}