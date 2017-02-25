#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <stdio.h>

using namespace std;

int main(){
	int n;
	while(scanf("%d", &n) != EOF && n){
		stack<int> st;
		char c;
		for(int i = 0; i < n; ++i){
			cin >> c;
			switch(c){
				case 'P':
					int a;
					cin >> a;
					st.push(a);
					break;
				case 'O':
					if(!st.empty()){
						st.pop();
					}
					break;
				case 'A':
					if(!st.empty()){
						cout << st.top() << endl;
					}else{
						cout << 'E' << endl;
					}
					break;
			}
		}
		cout << endl;
	}
	return 0;
}