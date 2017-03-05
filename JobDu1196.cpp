#include <stdio.h>
#include <algorithm>

using namespace std;

int n;

struct Student{
	int id;
	int score;
};
Student a[101];
bool cmp(const Student &s1, const Student &s2){
	if(s1.score == s2.score){
		return s1.id < s2.id;
	}else{
		return s1.score < s2.score;
	}
}

int main(){
	int i;
	while(scanf("%d", &n) != EOF){
		for(i = 0;i < n; ++i){
			scanf("%d%d", &a[i].id, &a[i].score);
		}
		sort(a, a+n, cmp);
		for(i = 0;i < n; ++i){
			printf("%d %d\n", a[i].id, a[i].score);
		}
	}
}