#include <stdio.h>
#include <string.h>
#include <iostream>

int key[1000000];
int a[505];

using namespace std;

int main(){
	int n, tmp;
	while(scanf("%d", &n) != EOF && n){
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}

		memset(key, 0, sizeof(key));
		for(int i = 0; i < n; ++i){
			tmp = a[i];
			while(tmp != 1){
				if(tmp & 1){
					tmp = tmp * 3 + 1;
					tmp /= 2;
				}else{
					tmp /= 2;
				}
				key[tmp] = 1;
			}
		}

		int flag = 0;
		for(int i = n -1; i >= 0; --i){
			if(key[a[i]] == 0){
				if(flag == 1){
					printf(" ");
				}
				printf("%d", a[i]);
				flag = 1;
			}
		}
		cout << endl;
	}
	return 0;
}