#include <iostream>

using namespace std;

int divi[1000001];
int main(){
	int n;
	divi[1] = 1;
	for(int i = 2; i <= 1000001; ++i){
		if(i &1) divi[i] = divi[i -1];
		else divi[i] = (divi[i -1] + divi[i /2]) % 1000000000;
	}
	while(cin >> n){
		cout << divi[n] << endl;
	}
	return 0;
}