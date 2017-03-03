#include <stdio.h>
#include <string.h>

#define N 1000
#define M 100

int match(char c1, char c2){
	if('A' <= c1 && c1 <= 'Z')
		c1 += 'a' - 'A';
	if('A' <= c2 && c2 <= 'Z')
		c2 += 'a' - 'A';
	return (c1 == c2);
}

int main(){
	int n, i, j, k;
	char s[N][M], mod[M];

	while(scanf("%d", &n) != EOF){
		for(i = 0; i < n; ++i)
			scanf("%s", s[i]);

		scanf("%s", mod);

		for(i = 0;i < n; ++i){
			for(j = 0, k = 0; j < strlen(s[i]) && k < strlen(mod); ++j, ++k){
				if(mod[k] == '['){
					while(mod[++k] != ']'){
						if(match(s[i][j], mod[k]))
							break;
					}
					if(mod[k] == ']') break;
					while(mod[k] != ']')
						++k;
				}else{
					if(!match(s[i][j], mod[k]))
						break;
				}
			}
			if(j == strlen(s[i]) && k == strlen(mod))
				printf("%d %s\n", i+1, s[i]);
		}

	}
	return 0;
}