#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>

using namespace std;

struct Item{
	string name;
	int m;
	vector<int> plms;
	int sum;
};

bool cmp(const Item& t1, const Item& t2){
	if(t1.sum > t2.sum){
		return true;
	}else if(t1.sum == t2.sum){

		if(t1.name.compare(t2.name) < 0){
			return true;
		}else{
			return false;
		}

	}else
		return false;
}

int main(){
	int n, m, g;
	while(scanf("%d", &n) != EOF && n){
		cin >> m >> g;
		vector<int> score(m+1, 0);
		for(int i = 1; i <= m; ++i){
			cin >> score[i];
		}
		vector<Item> record(n, Item());
		int count = 0;

		for(int i = 0; i < n; ++i){
			cin >> record[i].name >> record[i].m;
			int a;
			int sum = 0;
			for(int j = 0; j < record[i].m; ++j){
				cin >> a;
				record[i].plms.push_back(a);
				sum += score[a];
			}
			record[i].sum = sum;
			if(sum >= g)++count;
		}

		sort(record.begin(), record.end(), cmp);
		
		cout << count << endl;
		for(int i = 0; i < n; ++i){
			if(record[i].sum >= g){
				cout << record[i].name << ' ' << record[i].sum << endl;
			}
		}
		
	}
	return 0;
}
