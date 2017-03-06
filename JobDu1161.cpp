#include <iostream>
#include <cmath>

using namespace std;

const int N = 3000;
char b[N+10][N+10];

int main(){
	int n, q, dsize;
	char a[6][6];
	while(cin >> n /* scanf("%d\n", &n) != EOF */ && n){
		cin.get();
		for(int i = 0; i < n; ++i)
			cin.getline(a[i], 10);
		cin >> q;
		dsize = (int)pow((double)n, q);

		int t1, t2, m1, m2, tmp, j;
		for(int x = 0; x < dsize; ++x){
			for(int y = 0; y < dsize; ++y){
				t1 = x;
				t2 = y;
				j =	q;
				while(--j){
					tmp = (int)pow((double)n, j);
					m1 = t1 / (int)pow((double)n, j);
					m2 = t2 / (int)pow((double)n, j);
					if(a[m1][m2] == ' '){
						b[x][y] = ' ';
						break;
					}
					t1 = t1 % tmp;
					t2 = t2 % tmp;
				}
				if(!j){
					b[x][y] = a[t1][t2];
				}
			}
		}

		for(int x = 0; x < dsize; ++x){
			for(int y = 0; y < dsize; ++y){
				cout << b[x][y];
			}
			cout << endl;
		}
	}
}