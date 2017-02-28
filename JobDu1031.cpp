#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int n;
	int count;
	while(scanf("%d", &n) != EOF && n){
		count = 0;
		while(n != 1){
			if(n&1){
				n = 3 * n + 1;
				n /= 2;
			}else{
				n /= 2;
			}
			++count;
		}
		cout << count << endl;
	}
	return 0;
}