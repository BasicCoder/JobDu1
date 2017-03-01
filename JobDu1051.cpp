#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int a,n;
	while(scanf("%d%d", &a, &n)!= EOF){
		vector<int> vt(n,a);
		int i;
		for(i = 0; i < n; ++i){
			vt[i] = (n - i) * a;
		}

		int flag = 0;
		i = 0;
		while(i < n){
			vt[i] += flag;
			int tmp = vt[i] % 10;
			flag = vt[i] / 10;
			vt[i] = tmp;
			++i;
		}
		while(flag){
			int tmp = flag % 10;
			flag /= 10;
			vt.insert(vt.end(), tmp);
		}
		int len = vt.size();
		for( i = len -1; i >= 0; --i)
			cout << vt[i];
		cout << endl;
	}
	return 0;
}