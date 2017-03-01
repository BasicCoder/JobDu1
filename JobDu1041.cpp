#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <string.h>

using namespace std;

int a[1010];

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		memset(a, 0, sizeof(a));
		set<int> s;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			s.insert(a[i]);
		}
		set<int>::iterator it;
		for(it = s.begin(); it != s.end(); ++it){
			if(it == (--s.end())){
				cout << *it;
			}else{
				cout << *it << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}