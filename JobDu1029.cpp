#include <stdio.h>
#include <string>
#include <iostream>
#include <map>

using namespace std;

map<string, string> dic;

void filldic(string& str){
	int len = str.length();
	int i = 0;
	while(str[i] != ']') ++i;

	string s1 = str.substr(0, i+1);
	string s2 = str.substr(i+2, len - i -2);
	dic[s1] = s2;
	dic[s2] = s1;
}

int main(){
	char s[105];
	string str;
	int n;
	while(gets(s)){
		str = s;
		if(str == "@END@") break;
		filldic(str);
	}
	scanf("%d\n", &n);
	for(int i = 0; i < n; ++i){
		gets(s);
		str = s;
		if(dic.find(str) == dic.end()){
			cout << "what?\n"; 
		}else{
			str = dic[str];
			if(str[0] != '['){
				cout << str << endl;
			}else{
				cout << str.substr(1, str.length() - 2) << endl;
			}
		}
	}

	return 0;
}