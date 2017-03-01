#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

static const int MAXN = 200;
static const int ten[4] = {1, 10, 100, 1000};

struct BigInt{
	int d[MAXN];
	BigInt(string s){
		int len = s.length();
		int i, j, k;
		memset(d, 0, sizeof(d));
		d[0] = (len -1) /4 +1;

		for(i = len -1; i >= 0; --i){
			j = (len -1 -i)/4 +1;
			k = (len -1 -i)%4;
			d[j] += ten[k] * (s[(unsigned)i] - '0');
		}
		while(d[0] > 1 && d[d[0]] == 0) --d[0];
	}

	BigInt(){
		*this = BigInt("0");
	}
	string toString(){
		string s = "";
		int i, j, temp;
		for(i = 3; i >= 0; --i)
			if(d[d[0]] >= ten[i]) break;
		temp = d[d[0]];
		for(j = i; j >= 0; --j){
			s += (char)(temp/ten[j] + '0');
			temp %= ten[j];
		}

		for(i = d[0] -1; i > 0; --i){
			temp = d[i];
			for(j = 3; j >= 0; --j){
				s += (char)(temp/ten[j] + '0');
				temp %= ten[j];
			}
		}
		if(s == "") s = "0";
		return s;
	}
};

bool operator <(BigInt &a, BigInt &b){
	if(a.d[0] != b.d[0]) return a.d[0] < b.d[0];
	for(int i = a.d[0]; i >= 1; --i){
		if(a.d[i] != b.d[i]) return a.d[i] < b.d[i];
	}
	return false;
}

BigInt operator + (BigInt &a, BigInt &b){
	BigInt c;
	c.d[0] = max(a.d[0], b.d[0]);
	int i, x = 0;
	for(i = 1; i <= c.d[0]; ++i){
		x = (a.d[i] + b.d[i] + x);
		c.d[i] = x % 10000;
		x /= 10000;
	}
	while(x != 0){
		c.d[++c.d[0]] = x % 10000;
		x /= 10000;
	}
	return c;
}

BigInt operator - (BigInt &a, BigInt &b){
	BigInt c;
	c.d[0] = a.d[0];
	int i, x = 0;
	for(i = 1; i <= c.d[0]; ++i){
		x = (10000 + a.d[i] - b.d[i] + x);
		c.d[i] = x % 10000;
		x = x/10000 -1;
	}
	while(c.d[0] > 1 && c.d[c.d[0]] == 0) --c.d[0];
	return c;
}

BigInt operator * (BigInt &a, BigInt &b){
	BigInt c;
	c.d[0] = a.d[0] + b.d[0];
	int i, j, x = 0;
	for(i = 1; i <= a.d[0]; ++i){
		x  = 0;
		for(j = 1; j <= b.d[0]; ++j){
			x = (x + a.d[i] * b.d[j] + c.d[i+j-1]);
			c.d[i+j-1] = x % 10000;
			x /= 10000;
		}
		c.d[i+b.d[0]] = x;
	}

	while(c.d[0] > 1 && c.d[c.d[0]] == 0) --c.d[0];
	return c;
}


int main(){
	string a, b;
	while(cin >> a >> b){
		bool symbol_a = true;
		bool symbol_b = true;
		if(a[0] == '-'){
			symbol_a = false;
			a.erase(0,1);
		}
		if(b[0] == '-'){
			symbol_b = false;
			b.erase(0,1);
		}
		
		BigInt bigA = BigInt(a);
		BigInt bigB = BigInt(b);
		BigInt bigC;
		
		if(symbol_b == symbol_a){
			cout << (symbol_a ? "":"-") <<(bigA + bigB).toString() <<endl;
			if(bigA < bigB){
				cout << (symbol_a ? "-":"") << (bigB - bigA).toString() <<endl;
			}else{
				cout << (symbol_a ? "":"-") << (bigA - bigB).toString() <<endl;
			}
			cout << (bigA*bigB).toString() <<endl;
		}else{
			if(bigA < bigB){
				cout << (symbol_b ? "":"-") << (bigB - bigA).toString() <<endl;
			}else{
				cout << (symbol_a ? "":"-") << (bigA - bigB).toString() << endl;
			}

			cout << (symbol_a ? "":"-") << (bigA + bigB).toString() << endl;
			cout << "-" << (bigA * bigB).toString() << endl;
		}

	}
}