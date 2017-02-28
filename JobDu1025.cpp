#include <iostream>
#include <stdio.h>
#include <vector>

using  namespace std;

int data[31];
int len, maxa;
double ans, q;
int opt[3000000];

int main(){
	int n,m;
	char cc;
	while(scanf("%lf%d", &q, &n) != EOF && n){
		maxa = q * 100;
		len = 0;
		ans = -1;
		for(int i = 0; i < n; ++i){
			scanf("%d", &m);
			double a = 0, b = 0, c = 0, temp, sum = 0;
			int flag = 1;
			while(m--){
				scanf(" %c:%lf", &cc, &temp);

				if(cc == 'A') a += temp;
				else if(cc == 'B') b += temp;
				else if(cc == 'C') c += temp;
				else flag = 0;

				sum += temp;
			}

			if(flag && sum <= 1000 && a <= 600 && b <= 600 && c <= 600)
				data[len++] = sum * 100;
		}

		for(int i = 0; i <= maxa; ++i)
			opt[i] = 0;
		for(int i = 0; i < len; ++i){
			for(int j = maxa; j >= data[i]; --j){
				if(opt[j -data[i]] + data[i] > opt[j])
					opt[j] = opt[j -data[i]] + data[i];
			}
		}
		ans = opt[maxa] / 100.0;
		printf("%.*f\n", 2, ans);
	}
	return 0;
}