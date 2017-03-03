#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1001];
int n,k;
int main(){
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		scanf("%d", &k);
		sort(a, a+n);
		unique(a, a+n);
		printf("%d\n", a[k-1]);
	}
	return 0;
}