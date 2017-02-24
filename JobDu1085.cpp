#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

long long x, y, k, z;

long long QuickPow(long long n, long long base, long long k){
	long long ans = 1;
	while(n){
		if(n &1)
			ans = (base * ans) %k;
		base = (base * base) %k;
		n >>=1;
	}
	return ans;
}
int main(){
	while(scanf("%lld%lld%lld", &x, &y, &k) != EOF){
		z = QuickPow(y, x, k -1);
		if(z == 0)
			z = k -1;
		printf("%lld\n", z);
	}
	return 0;
}