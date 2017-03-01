#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

const int maxn = 3000;
int f[maxn];
int main(){
	int n;
	int i, j, len, num;
	while(scanf("%d", &n) != EOF){
		len = 1;
		memset(f, 0, sizeof(f));
		f[0] = 1;
		int c = 0;
		for(i = 2; i <= n; ++i){
			for(j = 0; j < len; ++j){
				num = f[j] * i + c;
				f[j] = num % 10;
				c = num / 10;
			}
			while(c){
				f[len++] = (c %10);
				c /= 10;
			}
		}
		for(j = maxn -1; j >= 0; --j)
			if(f[j])break;
		for(i = j; i >= 0; i--)
			cout << f[i];
		cout << endl;
	}
	return 0;
}