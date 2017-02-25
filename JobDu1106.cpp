#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int digits_sum(int n){
	int sum = 0;
	while(n){
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF && n){
		cout << digits_sum(n) << ' ' << digits_sum(n * n) << endl;
	}
}