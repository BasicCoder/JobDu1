#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <string>

using namespace std;

/*Warning£º This code is not Correct, But I can't find a sample to varify.
  Please find JobDu1019_1.cpp, the code of God.
*/

double computer(double a, double b, char c){
	double result = 0;
	switch(c){
		case '-':
			result = a - b;
			break;
		case '+':
			result = a + b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result = a / b;
			break;
	}
	return result;
}

double getResult(string& line){
	double result;

	int len = line.length();
	int i = 0;
	while(line[0] == ' ') ++i; 

	stack<double> nums;
	stack<char> op;

	for( ; i < len; ++i){
		if('0' <= line[i] && line[i] <= '9'){
			int a = 0;
			while('0' <= line[i] && line[i] <= '9'){
				a *= 10;
				a += (line[i] - '0');
				++i;
			}
			nums.push(a);
		}else if(line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/'){
			if(!op.empty()){
				if(line[i] == '+' || line[i] == '-'){
					while(!op.empty()){
						double a = nums.top();
						nums.pop();
						double b = nums.top();
						nums.pop();
						char c = op.top();
						op.pop();
						double result = computer(b, a, c);
						nums.push(result);
					}
					op.push(line[i]);
				}else{
					while(op.top() == '*' || op.top() == '/'){
						double a = nums.top();
						nums.pop();
						double b = nums.top();
						nums.pop();
						char c = op.top();
						op.pop();
						double result = computer(b, a, c);
						nums.push(result);
					}
					op.push(line[i]);
				}
			}else{

				op.push(line[i]);
			}
	
		}	
	}


	while(!op.empty()){
		double a = nums.top();
		nums.pop();
		double b = nums.top();
		nums.pop();
		char c = op.top();
		op.pop();
		double result = computer(b,a,c);
		nums.push(result);
	}
	return nums.top();

}

int main(){
	string line;
	while(getline(cin, line)){
		if(line == "0") break;
		printf("%.*f\n", 2, getResult(line));
	}
	return 0;
}