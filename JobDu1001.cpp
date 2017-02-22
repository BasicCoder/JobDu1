#include <iostream>
#include <vector>

using namespace std;

int main(){
	int M, N;
	while(cin >> M && M ){
		cin >> N;
		vector< vector<int> > m1(M, vector<int>(N,0));
		vector< vector<int> > m2(M, vector<int>(N,0));

		for(int i = 0; i < M; ++i){
			for(int j = 0; j < N; ++j){
				cin >> m1[i][j];
			}
		}

		for(int i = 0; i < M; ++i){
			for(int j = 0; j < N; ++j){
				cin >> m2[i][j];
			}
		}
        
		for(int i = 0; i < M; ++i){
			for(int j = 0; j < N; ++j){
				m1[i][j] += m2[i][j];
			}
		}

		int count = 0;
		for(int i = 0; i < M; ++i){
			bool flag = false;
			for(int j = 0; j < N; ++j){
				if(m1[i][j] != 0){
					flag = true;
					break;
				}
			}
			if(!flag) ++count;
		}

		for(int i = 0; i < N; ++i){
			bool flag = false;
			for(int j = 0; j < M; ++j){
				if(m1[j][i] != 0){
					flag = true;
					break;
				}
			}
			if(!flag) ++count;
		}

		cout << count << endl;

	}
	return 0;
}