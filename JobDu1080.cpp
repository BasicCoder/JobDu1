#include <iostream>
#include <stdio.h>
#include <stack>
#include <string.h>
#include <string>

using namespace std;

int main(){
	int m,n;
	string str;
	while(scanf("%d%d", &m, &n) != EOF){
		cin >> str;
		int data[1010];
		int output[1010];
		memset(output, 0, sizeof(output));

		int len = str.length();
		for(int i = 0; i < len; ++i){
			if(isalpha(str[i]))
				data[i] = str[i] - 'A' + 10;
			else
				data[i] = str[i] - '0';
		}
		int sum = 1;
		int d = 0;
		int k = 0;
		while(sum){
			sum = 0;
			for(int i = 0; i < len; ++i){
				d = data[i] / n;
				sum += d;
				if(i == len -1){
					output[k++] = data[i] % n;
				}else{
					data[i+1] += (data[i] % n) * m;
				}
				data[i] = d;
			}
		}

		if(k == 0){
			output[k] = 0;
			k--;
		}
		if(k == -1){
			cout << 0 << endl;
		}else{
			for(int i = 0; i < k; ++i){
				if(output[k -i -1] > 9){
					cout << (char)(output[k -i -1] + 'a' - 10);
				}else
					cout << output[k -i -1];
			}
		}
		cout << endl;
	}
	return 0;
}