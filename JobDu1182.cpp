#include <stdio.h>
#include <string.h>

char str[1010];

int main(){
	while(gets(str)){
		int i =0, index;
		while(str[i] == ' ')++i;

		while(str[i] != '\0'){
			index = i;

			while(str[i] != ' ' && str[i] != '.')++i;

			printf("%d", i -index);

			if(str[i] == ' ')
				printf(" ");
			else if(str[i] == '.')
				printf("\n");

			while((str[i] == ' ' || str[i] == '.') && str[i] != '\0')++i;
		}
	}
	return 0;
}
