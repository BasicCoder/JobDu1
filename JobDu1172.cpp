#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		vector<int> nums(n, 0);
		for(int i = 0; i < n; ++i){
			cin >> nums[i];
		}
		sort(nums.begin(), nums.end());
		int m = nums.size() -1;
		int res = 0;
		for(int i = 0; i < m; ++i){
			int cur = nums[0] + nums[1];
			res += cur;
			nums.erase(nums.begin());
			nums.erase(nums.begin());
			bool isfind = false;
			int size = nums.size();
			for(int i = 0; i < size; ++i){
				if(nums[i] > cur){
					nums.insert(nums.begin() +i, cur);
					isfind = true;
					break;
				}
			}
			if(!isfind) nums.push_back(cur);
		}
		cout << res << endl;
	}
	return 0;
}