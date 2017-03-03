#include <stdio.h>
#include <string.h>
#include <algorithm>

#define MAX 302

char toDo[10002][MAX];

struct Item{
	char name[12];
	char day[12];
	char times[20];
	double cost;
	int id;
};
Item task[10002];

int cmp(const void *a1, const void *b1){
	Item a = *(Item*)a1;
	Item b = *(Item*)b1;
	if(a.cost == b.cost){
		int tmpa = strcmp(a.day, b.day);
		if(tmpa == 0){
			int tmpb = strcmp(a.times, b.times);
			if(tmpb == 0){
				return a.id - b.id;
			}
			else{
				return tmpb;
			}
		}else{
			return tmpa;
		}
	}else{
		if(a.cost > b.cost){
			return 1;
		}else{
			return -1;
		}
	}
}


int main(){
	int k = 0;
	while(gets(toDo[k]) != 0){
		sscanf(toDo[k], "%s %s %s %lf", task[k].name, task[k].day, task[k].times, &task[k].cost);
		task[k].id = k;
		k++;
	}
	qsort(task, k, sizeof(Item), cmp);
	for(int i = 0; i < k; ++i){
		puts(toDo[task[i].id]);
	}

	return 0;
}