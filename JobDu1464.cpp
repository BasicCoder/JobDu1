#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(){
	string line;
	while(cin >> line){
		int len = line.length();
		int n = (len + 2) / 3;
		int m = len - n * 2;
		int i = 0;

		for( ; i < n -1; ++i){
			cout << line[i];
			int a = m;
			while(a){
				cout << ' ';
				--a;
			}
			cout << line[len-1 -i] << endl;
		}

		cout << line.substr(i, m+2) << endl;

	}
	return 0;
}