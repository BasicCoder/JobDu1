#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[101];

int main(){
	while(gets(str)){
		int len = strlen(str);
		for(int i = 0; i < len; ++i){
			if(str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n'){
				if( i+1 < len && 'a' <=  str[i+1] && str[i+1] <= 'z'){
					str[i+1] = str[i+1] - 'a' + 'A';
				}
			}
		}

		if('a' <= str[0] && str[0] <= 'z'){
			str[0] = str[0] - 'a' + 'A';
		}
		puts(str);

	}
	return 0;
}