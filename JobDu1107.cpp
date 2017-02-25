#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(){
	int n;
	
	while(scanf("%d", &n) != EOF && n){
		vector<int> nums(n, 0);
		for(int i = 0; i < n; ++i){
			cin >> nums[i];
		}

		sort(nums.begin(), nums.end());
		int result = 0;
		int count = nums.size() -1;
		for(int i = 0; i < count; ++i){
			int cur = nums[0] + nums[1];
			result += cur;
			nums.erase(nums.begin());
			nums.erase(nums.begin());
			bool find = false;
			for(int i = 0; i < nums.size(); ++i){
				if(nums[i] > cur){
					nums.insert(nums.begin() +i, cur);
					find = true;
					break;
				}
			}
			if(!find)nums.push_back(cur);
		}
		cout << result << endl;
	}
	return 0;
}