#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(){
	int n;
	string str;
	vector<string> v;
	while(scanf("%d", &n) != EOF && n){
		v.clear();
		while(n--){
			cin >> str;

			if(str[str.length() -1] == '\\'){
				str.erase(str.length() -1, str.length());
			}
			if(find(v.begin(), v.end(), str) == v.end()){
				v.push_back(str);
			}

			while(str.find('\\') != string::npos){
				str.erase(str.find_last_of('\\'), str.length());
				if(find(v.begin(), v.end(), str) == v.end()){
					v.push_back(str);
				}
			}
		}

		sort(v.begin(), v.end());
		for(int i = 0; i < v.size(); ++i){
			if(v[i].find('\\') == string::npos){
				cout << v[i] << endl;
			}else{
				for(int j = 0; j < v[i].find_last_of('\\'); ++j){
					cout << ' ';
				}
				cout << ' ';
				cout << v[i].substr(v[i].find_last_of('\\') +1, v[i].length());
				cout << endl;
			}
		}
		cout << endl;
		
	}
}