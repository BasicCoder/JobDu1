#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void shift_flip(vector<int>& vt, int index){
	reverse(vt.begin(), vt.begin() +index);
	reverse(vt.begin() +index, vt.end());
	reverse(vt.begin(), vt.end());
	int size = vt.size();
	if(size &1){
		reverse(vt.begin(), vt.begin() + (size-1)/2);
	}else{
		reverse(vt.begin(), vt.begin() + size /2);
	}
}

int main(){
	int n,k;
	while(scanf("%d%d", &n, &k) != EOF && n){
		vector<int> vt(n, 0);
		for(int i = 0; i < n; ++i){
			vt[i] = i+1;
		}
		int index = -1;
		for(int i = 0; i < k; ++i){
			cin >> index;
			shift_flip(vt, index);
		}

		for(int i = 0; i < n; ++i){
			cout << vt[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}