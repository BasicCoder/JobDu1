#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>

using namespace std;

void operator_str(string & str, int &A, int &B, int &C){
	int len = str.length();
	for(int i = 0; i < len; ++i){
		if(str[i] == '+')
			continue;
		else if(str[i] == '-'){

		}else if(str[i] == 'x'){
			if(i +1 < len && str[i+1] == '^'){
				if(i -1 >= 0 && str[i-1] == '-')
					A = A -1;
				else
					A += 1;
				i = i +3;
			}else{
				if(i -1 >= 0 && str[i-1] == '-')
					B = B -1;
				else
					B += 1;
				i = i +1;
			}
	
		}else{
			int temp = 0;
			int j = i;
			while('0' <= str[i] && str[i] <= '9'){
				temp = temp * 10 + str[i] - '0';
				++i;
			}
			if(j -1 >= 0 && str[j -1] == '-')
				temp = 0 - temp;
			if(i < len && str[i] == 'x'){
				if(i+1 < len && str[i+1] == '^'){
					A += temp;
					i = i +3;
				}else{
					B += temp;
					i = i +1;
				}
			}else{
				C += temp;
			}
		}
	}
}

int main(){
	string str;
	while(cin >> str){
		int j = 0;
		while(str[j] != '=' ) ++j;

		string str_left = str.substr(0, j);
		string str_right = str.substr(j+1);

		int A1 = 0, B1 = 0, C1 = 0;
		int A2 = 0, B2 = 0, C2 = 0;

		operator_str(str_left, A1, B1, C1);
		operator_str(str_right,A2, B2, C2);

		int a = A1 - A2;
		int b = B1 - B2;
		int c = C1 - C2;
		int temp = b * b - 4 * a * c;
		if(temp < 0)
			cout << "No Solution" << endl;
		else{
			double x1, x2;
			x1 = (double)(0 - b + sqrt((double)temp)) / (2 * a);
			x2 = (double)(0 - b - sqrt((double)temp)) / (2 * a);
			if(x1 < x2)
				printf("%.2lf %.2lf\n", x1, x2);
			else
				printf("%.2lf %.2lf\n", x2, x1);
		}
	}
	return 0;
}