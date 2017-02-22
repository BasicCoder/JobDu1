#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int str_to_int(string& s){
	int result = 0;
	int flag = 1;
	int length = s.length();

	if(s[0] == '-') flag = -1;
	else{
		result = s[0] - '0';
	}

	for(int i = 1; i < length; ++i){
		if(s[i] != ','){
			result *= 10;
			result += flag *(s[i] - '0');
		}
	}
	return result;
}

int main(){
	string a;
	string b;
	
	while(cin >> a >> b){
		int A = str_to_int(a);
		int B = str_to_int(b);
		cout << A + B << endl;
	}
	
	return 0;
}