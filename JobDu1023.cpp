#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

struct Student{
	string ID;
	string name;
	int score;

};

bool cmp1(const Student& s1, const Student& s2){
	if(s1.ID.compare(s2.ID) < 0) return true;
	else
		return false;
}

bool cmp2(const Student& s1, const Student& s2){
	int flag = s1.name.compare(s2.name);
	if(flag < 0) return true;
	else if(flag == 0){
		return (s1.ID.compare(s2.ID) < 0);
	}else
		return false;
}

bool cmp3(const Student& s1, const Student& s2){
	int flag = s1.score - s2.score;
	if(flag < 0)return true;
	else if(flag == 0){
		return (s1.ID.compare(s2.ID) < 0);
	}else
		return false;
}

int main(){
	int n,c;
	int m = 1;
	while(scanf("%d%d", &n, &c) != EOF && n){
		vector<Student> students(n, Student());
		for(int i = 0; i < n; ++i){
			cin >> students[i].ID >> students[i].name >> students[i].score;
		}
		
		switch(c){
			case 1:
				sort(students.begin(), students.end(), cmp1);
				break;
			case 2:
				sort(students.begin(), students.end(), cmp2);
				break;
			case 3:
				sort(students.begin(), students.end(), cmp3);
				break;
		}
		
		printf("Case %d:\n", m);
		for(int i = 0; i < n; ++i){
			cout << students[i].ID << ' ' << students[i].name << ' ' << students[i].score <<endl;
		}
		++m;	
	}
	return 0;
}