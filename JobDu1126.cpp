#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int count = 0;
		for(int i = 0; i < n; ++i){
			cin >> count;
			vector<int> nums(count, 0);
			vector<int> result;
			for(int j = 0; j < count; ++j){
				cin >> nums[j];
			}
			if(nums[0] != nums[1]){
				result.push_back(0);
			}
		
			for(int i = 1; i < count -1; ++i){
				if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
					result.push_back(i);
				}else if(nums[i-1] > nums[i] && nums[i] < nums[i+1]){
					result.push_back(i);
				}
			}

			if(nums[count -2] != nums[count -1]){
				result.push_back(count -1);
			}

			int size = result.size();
			for(int j = 0; j < size -1; ++j){
				cout << result[j] << ' ';
			}
			cout << result[size -1] << endl;
		}
		
	}
	return 0;
}