#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;


int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int index = -1;
		vector<int> ants(100, -2);
		int a,b;
		for(int i = 0; i < n; ++i){
			cin >> a >> b;
			ants[a] = b;
			if(b == 0)index = a;
		}

		vector<int> LtoR, RtoL;
		for(int i = index -1; i > 0; --i){
			if(ants[i] == 1) LtoR.push_back(i);
		}
		for(int i = index +1; i < 100; ++i){
			if(ants[i] == -1) RtoL.push_back(i);
		}
		int diff = LtoR.size() - RtoL.size();

		if(diff == 0) cout << "Cannot fall!" << endl;
		else if(diff > 0) cout << 100 - LtoR[LtoR.size() - diff] << endl;
		else cout << RtoL[RtoL.size() + diff] << endl;

	}
	return 0;
}