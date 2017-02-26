#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

struct Item{
	string ID;
	int h1;
	int m1;
	int s1;

	int h2;
	int m2;
	int s2;
	Item(){}
	Item(string _ID, int _h1, int _m1, int _s1, int _h2, int _m2, int _s2):
		   ID(_ID),  h1(_h1), m1(_m1), s1(_s1), h2(_h2), m2(_m2), s2(_s2){}
};

bool cmp1(const Item & t1, const Item & t2){
	if(t1.h1 < t2.h1){
		return true;
	}else if(t1.h1 == t2.h1){
		if(t1.m1 < t2.m1){
			return true;
		}else if(t1.m1 == t2.m1){
			if(t1.s1 < t2.s1){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}

	}else{
		return false;
	}
}

bool cmp2(const Item & t1, const Item & t2){
	if(t1.h2 < t2.h2){
		return true;
	}else if(t1.h2 == t2.h2){
		if(t1.m2 < t2.m2){
			return true;
		}else if(t1.m2 == t2.m2){
			if(t1.s2 < t2.s2){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}

	}else{
		return false;
	}
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int m;
		for(int i = 0; i < n; ++i){
			cin >> m;
			vector<Item> record(m, Item());
			for(int i = 0; i < m; ++i){
				cin >> record[i].ID;
				scanf("%d:%d:%d", &record[i].h1, &record[i].m1, &record[i].s1);
				scanf("%d:%d:%d", &record[i].h2, &record[i].m2, &record[i].s2);
			
			}
			sort(record.begin(), record.end(), cmp1);
			cout << record[0].ID << ' ';
			sort(record.begin(), record.end(), cmp2);
			cout << record[m-1].ID << endl;
		}	
	}
	return 0;
}