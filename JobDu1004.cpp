#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;


int findKth(vector<int>& nums1, int i1, vector<int>& nums2, int i2, int k){
	if(i1 >= nums1.size()){
		return nums2[i2 + k -1];
	}
	if(i2 >= nums2.size()){
		return nums1[i1 + k -1];
	}
	if(k == 1){
		return min(nums1[i1], nums2[i2]);
	}

	int key1 = i1 + k/2 -1 >= nums1.size() ? INT_MAX:nums1[i1 + k/2 -1];
	int key2 = i2 + k/2 -1 >= nums2.size() ? INT_MAX:nums2[i2 + k/2 -1];
	
	if(key1 < key2){
		return findKth(nums1, i1 + k/2, nums2, i2, k - k/2);
	}else{
		return findKth(nums1, i1, nums2, i2 + k/2, k - k/2);
	}
}
int findMedian(vector<int>& nums1, vector<int>& nums2){
	int len1 = nums1.size();
	int len2 = nums2.size();

	int len = len1 + len2;
	if(len & 1){
		return findKth(nums1, 0, nums2, 0, len/2 +1);
	}else{
		return findKth(nums1, 0, nums2, 0, len/2);
	}
	
}

int main(){
	int n, m;
	while(cin >> n){
		vector<int> s1(n, 0);
		for(int i = 0; i < n; ++i){
			cin >> s1[i];
		}

		cin >> m;
		vector<int> s2(m, 0);
		for(int i = 0; i < m; ++i){
			cin >> s2[i];
		}
		
		int median = findMedian(s1, s2);
		cout << median << endl;
	
	}
	return 0;
}