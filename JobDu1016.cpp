#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int base[] = {2,3,5,7,11,
			  13,17,
			  19,23,29,
			  31,37,41,
			  43,47,53,
			  59,61,67,
			  71,73,79,
			  83,89,97			
};

void add(string& a, string& b){
	int len1 = a.length();
	int len2 = b.length();
	
	stack<int> s1;
	stack<int> s2;
	stack<int> res;

	//cout << "num1:";
	for(int i = 0; i < len1; ++i){
		int num = 0;
		while(a[i] != ',' && a[i] != '\0'){
			num *= 10;
			num += (a[i] - '0');
			++i;
		}
		//cout << num << ' ';
		s1.push(num);
	}
	//cout << endl;
	
	//cout << "num2:";
	for(int i = 0; i < len2; ++i){
		int num = 0; 
		while(b[i] != ',' && b[i] != '\0'){
			num *= 10;
			num += (b[i] - '0');
			++i;
		}
		//cout << num << ' ';
		s2.push(num);
	}
	//cout << endl;

	int flag = 0;
	int tmp = 0;
	int i = 0;
	while(!s1.empty() && !s2.empty()){
		tmp = s1.top() + s2.top() + flag;
		flag = tmp / base[i];
		tmp -= flag * base[i];
		
		res.push(tmp);
		s1.pop();
		s2.pop();
		++i;
	}

	while(!s1.empty()){
		tmp = s1.top() + flag;
		flag = tmp / base[i];
		tmp -= flag * base[i];
		res.push(tmp);
		s1.pop();
		++i;
	}
	while(!s2.empty()){
		tmp = s2.top() + flag;
		flag = tmp / base[i];
		tmp -= flag * base[i];
		res.push(tmp);
		s2.pop();
		++i;
	}
	
	if(flag > 0) res.push(flag);
	while(!res.empty()){
		if(res.size() == 1) break;
		cout << res.top() << ',';
		res.pop();
	}
	cout << res.top() << endl;

}

int main(){
	string A,B;
	while(cin >> A >> B){
		if(A == "0" && B == "0") break;
		add(A,B);
	}

}