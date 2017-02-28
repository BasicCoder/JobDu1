#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Station{
	double price;
	double dis;
};

Station sta[502];

bool cmp(const Station& s1, const Station& s2){
	return s1.dis < s2.dis;
}

int main(){
	double cmax, d, davg;
	int n, i, j;
	double nowgas, length, cost;
	while(scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n) != EOF){
		nowgas = 0;
		length = 0;
		cost = 0;
		for(i = 0; i < n; ++i){
			scanf("%lf%lf", &sta[i].price, &sta[i].dis);
		}

		sort(sta, sta + n, cmp);

		if(n == 0 || sta[0].dis != 0){
			printf("The maximum travel distance = 0.00\n");
			continue;
		}
		sta[n].price = 0;
		sta[n].dis = d;
		for(i = 0; i < n; ++i){
			if(cmax*davg < sta[i+1].dis - sta[i].dis){
				length += cmax * davg;
				break;
			}else if(sta[i+1].price <= sta[i].price){
				if(nowgas*davg >= sta[i+1].dis - sta[i].dis){
					length += sta[i+1].dis - sta[i].dis;
					nowgas -= (sta[i+1].dis - sta[i].dis)/davg;
				}else{
					length += sta[i+1].dis - sta[i].dis;
					cost += ((sta[i+1].dis - sta[i].dis)/davg - nowgas) *sta[i].price;
					nowgas = 0;
				}
			}else{
				int len = cmax * davg;
				j = i +1;
				int next = i+1;
				int min = sta[i+1].price;
				while(sta[j].dis - sta[i].dis <= len){
					if(min >= sta[j].price){
						next = j;
						min = sta[i].price;
					}
					if(sta[j].price <= sta[i].price){
						break;
					}
					++j;
				}

				if(sta[j].dis - sta[i].dis <= len){
					if(nowgas * davg < sta[j].dis - sta[i].dis){
						cost += (sta[j].dis - sta[i].dis - nowgas*davg)/ davg * sta[i].price;
						nowgas = 0;
						length += sta[j].dis - sta[i].dis;
					}else{
						length += sta[j].dis - sta[i].dis;
						nowgas -= (sta[j].dis - sta[i].dis) / davg;
					}
					i = j -1;
				}else{
					j = next;
					cost += (cmax - nowgas) * sta[i].price;
					nowgas = cmax - (sta[j].dis - sta[i].dis) / davg;
					length += sta[j].dis - sta[i].dis;
					i = j -1;
				}

			}
		}

		if(i < n){
			printf("The maximum travel distance = %.2lf\n",length);
		}else{
			printf("%.2lf\n", cost);
		}
	}
	return 0;

}