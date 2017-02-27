#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Boat{
	int flag;
	int number;
	int start;
	int time;
};


Boat boat[100];
int main(){
	int n;
	char k;
	int hour,min;
	int boatCount;
	double boatTime;
	while(scanf("%d", &n) != EOF && n != -1){
		boatCount = 0; 
		boatTime = 0;
		while(n){
			scanf(" %c %d:%d", &k, &hour, &min);
			if(k == 'S'){
				boat[n].number = n;
				boat[n].start = hour *60 + min;
				boat[n].flag = 1;
			}else if(k == 'E'){
				if(boat[n].flag == 1){
					boat[n].time = (hour * 60 + min) - boat[n].start;
					boatCount++;
					boatTime += boat[n].time;
				}
			}
			scanf("%d", &n);
		}

		scanf(" %c %d:%d", &k, &hour, &min);

		if(boatCount != 0){
			printf("%d %.0f\n", boatCount, boatTime/boatCount);
		}else{
			printf("0 0\n");
		}
	}
	return 0;
}