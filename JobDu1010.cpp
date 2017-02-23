#include <iostream>
#include <string>

using namespace std;
string digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int StrToInt(string &s){
	int index = 0, i = 0, j = 0;
	int length = s.length();
	while(index < length && s[index] != ' ') ++index;

	if(index != length){
		string s1 = s.substr(0, index);
		for(; i < 9; ++i) if(s1 == digits[i]) break;

		string s2 = s.substr(index + 1, length - index);
		for(; j < 9; ++j) if(s2 == digits[j])break;

		return i * 10 + j;
	}else{
		string s1 =  s.substr(0, index);
		for( ; i < 9; ++i)if(s1 == digits[i]) break;
		return i;
	}
}

int main(){
	string s;
	while(getline(cin, s)){
		string s1, s2;
		int index1 = 0;
		for( ; index1 < s.size(); ++index1){
			if(s[index1] == '+') break;
		}
		int index2 = index1;
		for( ; index2 < s.size(); ++index2){
			if(s[index2] == '=') break;
		}
		s1 = s.substr(0, index1 -1);
		s2 = s.substr(index1 +2, index2 - index1 -3);
		int ret = StrToInt(s1) + StrToInt(s2);
		if(ret == 0) return 0;
		else cout << ret << endl;
	}
	return 0;
}