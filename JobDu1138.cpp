#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int main(){
	int a, b;
	string str;
	while(cin >> str){
		int data[100];
		int output[1010];

		memset(output, 0, sizeof(output));

		int len = str.length();
		for(int i = 0; i < len; ++i){
			data[i] = str[i] - '0';
		}
		
		int sum = 1;
		int d = 0;
		int k = 0;
		while(sum){
			sum = 0;
			for(int i = 0; i < len; ++i){
				d = data[i] / 2;
				sum += d;
				if(i == len -1){
					output[k++] = data[i] % 2;
				}else{
					data[i+1] +=(data[i] % 2) * 10;
				}
				data[i] = d;
			}
		}

		if(k == 0){
			output[k] = 0;
			--k;
		}

		if(k == -1)
			cout << 0 << endl;
		else{
			for(int i = 0; i < k; ++i){
				cout << output[k -i -1];
			}
		}
		cout << endl;
	}
}