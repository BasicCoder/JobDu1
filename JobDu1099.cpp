#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	string str;
	vector<string> vt;

	while(cin >> str){
		vt.clear();
		int length = str.length();
		for(int i = 0; i < length; ++i){
			string tmp = str.substr(i, length - i);
			vt.push_back(tmp);
		}

		sort(vt.begin(), vt.end());
		int size = vt.size();
		for(int i = 0; i < size; ++i){
			cout << vt[i] << endl;
		}
	}
}