#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, m;
	while(cin>> n >> m){
		int reader[201] = {-1};
		int book[201] = {0};
		for(int i = 0; i < n; ++i){
			cin >> reader[i];
			book[reader[i]]++;
		}
		for(int i = 0;i < n; ++i){
			if(book[reader[i]] == 1 ){
				cout << "BeiJu" << endl;
			}else{
				cout << book[reader[i]] - 1 << endl;
			}
		}
	}

}