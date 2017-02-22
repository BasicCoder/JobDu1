#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

#define IsLeap(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1: 0

using namespace std;

int dayOfMonth[13][2] = {
	           0, 0,  // 0
			   31,31, // 1
			   28,29, // 2
			   31,31, // 3
			   30,30, // 4
			   31,31, // 5
			   30,30, // 6
			   31,31, // 7
			   31,31, // 8
			   30,30, // 9
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

int counts[3001][13][32];

char monthName[13][20] = {
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December",
};

char weekName[7][20] ={
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
};

int main(){
	Date tmp;
	int cnt = 0;
	tmp.day = 1;
	tmp.month = 1;
	tmp.year = 0;
	while(tmp.year != 3001){
		counts[tmp.year][tmp.month][tmp.day] = cnt;
		tmp.nextDay();
		++cnt;
	}

	int d, m, y;
	char s[20];

	while(scanf("%d%s%d",&d, s, &y) != EOF){
		for(m = 1; m <= 12; ++m){
			if(strcmp(s,monthName[m]) == 0){
				break;
			}
		}

		int days = counts[y][m][d] - counts[2017][2][22];
		days += 3;
		
		puts(weekName[(days % 7 + 7) % 7]);
	}
	return 0;
	
}