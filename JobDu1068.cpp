#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

int main(){
	double x0, y0, z0, x1, y1, z1;
	double r, v;
	while(scanf("%lf%lf%lf%lf%lf%lf", &x0, &y0, &z0, &x1, &y1, &z1) != EOF){
		r = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1) + (z0 - z1) * (z0 - z1));
		v = 4.0 * acos(-1.0) * r * r * r / 3.0;
		printf("%.3lf %.3lf\n", r, v);
	}
	return 0;
}