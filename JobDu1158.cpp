#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){
	int n, k;
	while(scanf("%d%d", &n, &k)!= EOF){
		int m = 1;
		double sum = n;
		double price = 200.0;
		while(sum < price && m <= 20){
			sum += n;
			price += price * (k /100.0);
			++m;
		}
		if(m <= 20){
			cout << m << endl;
		}else{
			cout << "Impossible" << endl;
		}
	}
	return 0;
}