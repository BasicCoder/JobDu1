#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1002

int main(){
	int i, start, end, mid;

	char str[MAX];

	while(scanf("%s", str) != EOF){
		start = 0;
		mid = 0;
		end = 0;
		i = 0;
		while(str[i] == 'o'){
			start++;
			i++;
		}

		if(str[i] != 'z'){
			printf("Wrong Answer\n");
			continue;
		}

		i++;
		while(str[i] == 'o'){
			mid++;
			i++;
		}

		if(str[i] != 'j'){
			printf("Wrong Answer\n");
			continue;
		}

		i++;

		while(str[i] == 'o'){
			end++;
			i++;
		}

		if(str[i] != '\0'){	
			printf("Wrong Answer\n");
			continue;
		}

		if(end ==  start * mid && mid >0)
			printf("Accepted\n");
		else
			printf("Wrong Answer\n");
	}
		return 0;
}
