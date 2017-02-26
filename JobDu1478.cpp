#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int a, b, c;
	int nums[3];
	while(scanf("%d%d%d", &a, &b, &c) != EOF && a){
		nums[0] = a;
		nums[1] = b;
		nums[2] = c;
		sort(nums, nums +3);
		cout << nums[0] + nums[1] - nums[2] << endl;
	}
}