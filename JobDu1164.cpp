#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;


vector< vector<int> > Rot90(vector< vector<int> >& mat1){
	int size = mat1.size();
	vector< vector<int> > mat2(size, vector<int>(size, 0));
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j){
			mat2[i][j] = mat1[size -j -1][i];
		}
	}
	return mat2;
}
bool isEqual(vector< vector<int> >& mat1, vector< vector<int> >& mat2){
	int size = mat1.size();
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j){
			if(mat1[i][j] != mat2[i][j]) return false;
		}
	}
	return true;
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		vector< vector<int> > mat1(n, vector<int>(n, 0));
		vector< vector<int> > mat2(n, vector<int>(n, 0));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> mat1[i][j];
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> mat2[i][j];
			}
		}
		vector< vector<int> > tmp(n, vector<int>(n, 0));
		if(isEqual(mat1, mat2)){
			cout << 0 << endl;
			continue;
		}
		tmp = Rot90(mat1);
		if(isEqual(tmp, mat2)){
			cout << 90 << endl;
			continue;
		}

		tmp = Rot90(tmp);
		if(isEqual(tmp, mat2)){
			cout << 180 << endl;
			continue;
		}

		tmp = Rot90(tmp);
		if(isEqual(tmp, mat2)){
			cout << 270 << endl;
			continue;
		}
		cout << -1 << endl;
		
	}
	return 0;
}