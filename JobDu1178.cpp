#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

struct Node{
	int x;
	int y;
	bool operator < (const Node &a)const{
		if((x*x + y*y) == (a.x * a.x + a.y * a.y)) return y > a.y;
		else return (x*x+y*y) < (a.x * a.x + a.y * a.y);
	}
};

int main(){
	int n;
	int i;
	string ins;
	while(scanf("%d", &n) != EOF){
		priority_queue<Node> pq;
		for(i = 0; i < n; ++i){
			cin >> ins;
			if(ins == "Pop"){
				if(pq.empty()){
					cout << "empty" << endl;
				}else{
					Node tmp = pq.top();
					cout << tmp.x << "+i" << tmp.y << endl;
					pq.pop();
					cout << "SIZE = " << pq.size() << endl;
				}
			}else if(ins == "Insert"){
				Node tmp;
				scanf("%d+i%d", &tmp.x, &tmp.y);
				pq.push(tmp);
				cout << "SIZE = " << pq.size() << endl;
			}
		}
	}

}