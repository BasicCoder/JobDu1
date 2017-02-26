#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	int n = 0;
	while(scanf("%d", &n) != EOF && n){
		vector<int> nums(n, 0);
		for(int i = 0; i < n; ++i){
			cin >> nums[i];
		}

		sort(nums.begin(), nums.end());
		if(n&1){
			cout << nums[n/2] << endl;
		}else{
			cout << (nums[n/2 -1] + nums[n/2])/2 << endl;
		}
	}
}