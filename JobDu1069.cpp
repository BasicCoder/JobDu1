#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

struct Student{
	string ID;
	string name;
	string gender;
	int age;
};

Student students[1001];

map<string, int> prime;

int main(){
	int n, m;
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; ++i){
			cin >> students[i].ID >> students[i].name >> students[i].gender >> students[i].age;
			prime[students[i].ID] = i;
		}

		scanf("%d", &m);
		string id;
		for(int i = 0; i < m; ++i){
			cin >> id;
			if(prime.find(id) == prime.end()){
				cout << "No Answer!" << endl;
			}else{
				int a = prime[id];
				cout << students[a].ID << ' ' << students[a].name << ' ' << students[a].gender << ' ' << students[a].age << endl;
			}
		}
	}
	return 0;
}