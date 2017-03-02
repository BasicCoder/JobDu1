#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int main(){
	int a, b;
	string str;
	while(scanf("%d", &a) != EOF){
		cin >> str;
		scanf("%d", &b);

		int data[1010];
		int output[1010];
		memset(output, 0, sizeof(output));

		int len = str.length();
		for(int i = 0; i < len; ++i){
			if(islower(str[i])){
				data[i] = str[i] - 'a' + 10;
			}else if(isupper(str[i])){
				data[i] = str[i] - 'A' + 10;
			}else{
				data[i] = str[i] - '0';
			}
		}

		int sum = 1;
		int d = 0;
		int k = 0;
		while(sum){
			sum = 0;
			for(int i = 0; i < len; ++i){
				d = data[i] / b;
				sum += d;
				if(i == len -1){
					output[k++] = data[i] % b;
				}else{
					data[i+1] += (data[i] % b) * a;
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
					cout << (char)(output[k -i -1] + 'A' -10);
				}else{
					cout << output[k -i -1];
				}
			}
		}
		cout << endl;
	}
	return 0;
}