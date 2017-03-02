#include <stdio.h>
#include <string.h>

#define MAX 1001

double stack[MAX];
int tail;

int main(){
	int a;
	while(scanf("%d", &a)!=EOF){
		tail = 0;
		stack[++tail] = 1.0 * a;
		char ch1;
		while(scanf("%c", &ch1) != EOF && ch1 != '\n'){
			scanf("%d", &a);
			if(ch1 == '+'){
				stack[++tail] = 1.0 * a;
			}else if(ch1 == '-'){
				stack[++tail] = -1.0 * a;
			}else if(ch1 == '*'){
				stack[tail] = stack[tail] * a;
			}else if(ch1 == '/'){
				stack[tail] = stack[tail] / (double)a;
			}
		}

		double result = 0;
		for(int i =1; i <= tail; ++i)
			result += stack[i];
		printf("%d\n", (int)result);
	}
}