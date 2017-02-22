#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>

#define IsLeap(x)  x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0

int dayOfMonth[13][2] = {
			   0, 0,  //0
			   31,31, //1
			   28,29, //2
			   31,31, //3
			   30,30, //4
			   31,31, //5
			   30,30, //6
			   31,31, //7
			   31,31, //8
			   30,30, //9
			   31,31, //10
			   30,30, //11
			   31,31  //12

};

struct Date{
	int day;
	int month;
	int year;
	void nextDay(){
		++day;
		if(day > dayOfMonth[month][IsLeap(year)]){
			day = 1;
			++month;
			if(month > 12){
				month = 1;
				++year;
			}
		}
	}
};

using namespace std;

int counts[5001][13][32];

int main(){
	Date tmp;
	int cnt = 0;
	tmp.day = 1;
	tmp.month = 1;
	tmp.year = 0;
	
	while(tmp.year != 5001){
		counts[tmp.year][tmp.month][tmp.day] = cnt;
		tmp.nextDay();
		++cnt;
	}

	int d1, m1, y1;
	int d2, m2, y2;

	while( scanf("%4d%2d%2d", &y1, &m1, &d1) != EOF){
		scanf("%4d%2d%2d", &y2, &m2, &d2);

		printf("%d\n", abs(counts[y2][m2][d2] - counts[y1][m1][d1]) + 1);
	}

	return 0;
}