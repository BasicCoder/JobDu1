#include <stdio.h>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
	long long a,b,sum;

	int m;
	while(scanf("%d", &m) != EOF && m){
		scanf("%lld%lld", &a, &b);
		sum = a + b;
		if(sum == 0){
			cout << 0 << endl;
			continue;
		}
		stack<int> digits;
		while(sum){
			int tmp = sum % m;
			digits.push(tmp);
			sum /= m;
		}
		
		while(!digits.empty()){
			cout << digits.top();
			digits.pop();
		}
		cout << endl;
	}
	return 0;
}