#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

int n;

int fun(int n){
	int num = 0;
	int a = (int)sqrt((double)n);
	for(int i = 1; i <= a; ++i){
		if(n %i == 0)
			num = num + 2;
	}
	if(a * a == n)num--;
	return num;
}
int main(){
	int i,num;
	while(scanf("%d", &n) != EOF && n){
		for(i = 0; i < n; ++i){
			cin >> num;
			cout << fun(num) << endl;
		}
	}
}