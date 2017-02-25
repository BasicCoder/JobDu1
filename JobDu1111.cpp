#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

int main(){
	string line;
	while(getline(cin, line)){
		string src,dst;
		getline(cin, src);
		getline(cin, dst);
		
		int len1 = src.length();
		int len2 = dst.length();
		int i = 0;
		while(line[i] == ' ') ++i;

		
		for( ; i < line.length(); ++i){
			int index = i;
			while(line[i] != ' ' && line[i] != '\0') ++i;
			string tmp = line.substr(index, i - index);

			if(tmp == src){
				line.erase(index, i -index);
				line.insert(index, dst);
				i = i - len1 + len2;
			}
		}
		cout << line << endl;

	}
	return 0;
}