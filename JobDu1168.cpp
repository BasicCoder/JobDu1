#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[200], s2[200], in[100][100], in2[100][100], t;
int i, j, len, slen, end;

void trans(char *a, char *b, int len){
	int i;
	for(i = 0;i < len; ++i){
		if(a[i] >= 'A' && a[i] <= 'Z')
			b[i] = a[i] + 32;
		else
			b[i] = a[i];
	}
	b[i] = '\0';
}
int main(){
	gets(s);
	len = strlen(s); 
	trans(s, s2, len);
	i = 0;
	while(gets(in[i]) != NULL){
		trans(in[i], in2[i], strlen(in[i]));
		i++;
	}

	slen = i;
	for(i = 0; i < slen; ++i){
		j = 0;
		while(strlen(in2[i]) -j >= len ){
			end = j + len;
			t = in2[i][end];
			in2[i][end] = '\0';
			if(strcmp(s2, &in2[i][j]) == 0){
				for( ; j < end; ++j)
					in2[i][j] = ' ';
			}else{
				++j;
			}
			in2[i][end] = t;
		}
	}

	for( i = 0; i < slen; ++i){
		for(j = 0; j < strlen(in2[i]); ++j){
			if(in2[i][j] != ' ')
				printf("%c", in[i][j]);
		}
		if(i != slen -1)
			printf("\n");
	}
	return 0;
}