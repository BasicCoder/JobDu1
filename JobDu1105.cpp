#include <iostream>
#include <string>

using namespace std;

int main(){
	string str;
	while(getline(cin, str)){
		int length = str.length();

		if(str == "!") break;

		for(int i = 0; i < length; ++i){
			if( 'a' <= str[i] && str[i] <= 'z'){
				str[i] = 'z' - (str[i] - 'a');
			}else if('A' <= str[i] && str[i] <= 'Z'){
				str[i] = 'Z' - (str[i] - 'A');
			}
		}

		cout << str << endl;
	}
	return 0;
}