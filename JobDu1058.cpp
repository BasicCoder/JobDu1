#include <stdio.h>

//using namespace std;

char s[5];

int main(){
	while(gets(s)){
		char c = s[0];
		s[0] = s[3];
		s[3] = c;
		c = s[1];
		s[1] = s[2];
		s[2] = c;
		printf("%s\n", s);
	}
}