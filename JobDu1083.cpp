#include <iostream>
#include <string>

using namespace std;

int main(){
	string s1, s2;
	while(cin >> s1 >> s2){
		int result = 0;
		int len1 = s1.length();
		int len2 = s2.length();
		for(int i = 0; i < len1; ++i){
			for(int j = 0; j < len2; ++j){
				result += (s1[i] - '0') * (s2[j] - '0');
			}
		}
		cout << result << endl;
	}
}