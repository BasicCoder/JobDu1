#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

struct Student{
	string name;
	int age;
	int grade;
};

bool cmp(const Student &s1, const Student &s2){
	if(s1.grade != s2.grade){
		return s1.grade < s2.grade;
	}else{
		if(s1.name != s2.name){
			return s1.name.compare(s2.name) < 0;
		}else{
			return s1.age < s2.age;
		}
	}
}

Student stu[1001];
int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; ++i){
			cin >> stu[i].name >> stu[i].age >> stu[i].grade;
		}
		sort(stu, stu + n, cmp);
		for(int i = 0; i < n; ++i){
			cout << stu[i].name << ' ' << stu[i].age << ' ' << stu[i].grade << endl;
		}
	}
}