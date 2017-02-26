#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

bool isExist(int n){
	for(int i = 2; i <= (int) sqrt((double)n); ++i){
		if(n % (i*i) == 0){
			return true;
		}
	}
	return false;
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF && n){
		if(isExist(n))cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}