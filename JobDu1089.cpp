#include <iostream>
#include <math.h>

using namespace std;

int rever(int a){
	int result = 0;
	while(a){
		result *= 10;
		result += (a %10);
		a /= 10;
	}
	return result;
}

int main(){
	int n;
	cin >> n;
	int a, b, sum;
	int a1, b1, sum1;
	for(int i = 0; i < n; ++i){
		cin >> a >> b;
		sum = a + b;

		sum1 = rever(a) + rever(b);
		if(sum1 == rever(sum)){
			cout << sum << endl;
		}else{
			cout << "NO\n";
		}
	}
	return 0;
}