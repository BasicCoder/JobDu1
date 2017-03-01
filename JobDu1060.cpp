#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;



int main(){
	vector<int> E;
	vector<int> G;
	for(int i = 2; i <= 60; ++i){
		int sum = 0; 
		for(int j = 1; j < i; ++j){
			if(i % j == 0){
				sum += j;
			}
		}
		if(sum == i){
			E.push_back(i);
		}else if(sum > i){
			G.push_back(i);
		}
	}
	int i;
	int size1 = E.size();
	cout << "E: ";
	for(i = 0; i < size1 -1; ++i)
		cout << E[i] << ' ';
	cout << E[i] << endl;

	int size2 = G.size();
	cout << "G: ";
	for(i = 0; i < size2 -1; ++i)
		cout << G[i] << ' ';
	cout << G[i] << endl;
	return 0;


}