#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <limits.h>

using namespace std;

struct Country{
	int id;
	int rank[5];
	double golden_medal;
	double medal;
	double population;
	
};

bool golden_medal_cmp(const Country &a, const Country &b){
	return a.golden_medal > b.golden_medal;
}

bool medal_cmp(const Country &a, const Country &b){
	return a.medal > b.medal;
}

bool golden_medal_percent_cmp(const Country &a, const Country &b){
	return a.golden_medal / a.population > b.golden_medal / b.population;
}

bool medal_percent_cmp(const Country &a, const Country &b){
	return a.medal / a.population > b.medal / b.population;
}

bool id_cmp(const Country &a, const Country &b){
	return a.id < b.id;
}

int id;
Country countries[100000];
vector<Country> vt;

int main(){
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF){
		vt.clear();
		for(int i = 0; i < n; ++i){
			countries[i].id = i;
			cin >> countries[i].golden_medal >> countries[i].medal >> countries[i].population;
		}

		for(int i = 0; i < m; ++i){
			cin >> id;
			vt.push_back(countries[id]);
		}

		sort(vt.begin(), vt.end(), golden_medal_cmp);

		for(int i = 0; i < vt.size(); ){
			int next = i +1;
			for( ; next < vt.size() && vt[i].golden_medal == vt[next].golden_medal; ++next){}
			for(int j = i; j< next; ++j){
				vt[j].rank[1] = i+1;
			}
			i = next;
		}

		sort(vt.begin(), vt.end(), medal_cmp);
		for(int i = 0; i < vt.size(); ){
			int next = i +1;
			for( ; next < vt.size() && vt[i].medal == vt[next].medal; ++next){}
			for(int j = i; j < next; ++j){
				vt[j].rank[2] = i +1;
			}
			i = next;
		}

		sort(vt.begin(), vt.end(), golden_medal_percent_cmp);
		for(int i = 0; i < vt.size(); ){
			int next = i +1;
			for( ; next < vt.size() && vt[i].golden_medal / vt[i].population == vt[next].golden_medal/vt[next].population; ++ next){}
			for(int j = i; j < next; ++j){
				vt[j].rank[3] = i +1;
			}
			i = next;
		}

		sort(vt.begin(), vt.end(), medal_percent_cmp);

		for(int i = 0; i < vt.size(); ){
			int next = i +1;
			for( ; next < vt.size() && vt[i].medal / vt[i].population == vt[next].medal / vt[next].population; ++ next){}
			for(int j = i; j < next; ++j){
				vt[j].rank[4] = i +1;
			}
			i = next;
		}

		sort(vt.begin(), vt.end(), id_cmp);
		for(int i = 0; i < vt.size(); ++i){
			int rank = INT_MAX;
			int index = -1;
			for(int j = 1; j <=4; ++j){
				if(rank > vt[i].rank[j]){
					rank = vt[i].rank[j];
					index = j;
				}
			}
			cout << rank << ':' << index << endl;
		}
		cout << endl;
	}
	return 0;
}