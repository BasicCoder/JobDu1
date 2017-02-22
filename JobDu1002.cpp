#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;



int main(){
	double p, t, g1, g2, g3, gj;
	while( scanf("%lf%lf%lf%lf%lf%lf", &p, &t, &g1, &g2, &g3, &gj) != EOF){
		if( t > p || g1 > p || g2 > p || g3 > p || gj > p) return 0;

		if(fabs(g1 - g2) <= t){
			printf("%.*lf\n", 1, (g1+g2)/2.0);
		}else{
			if(fabs(g3 - g1) > t && fabs(g3 - g2) > t){

				printf("%.*lf\n", 1, gj);

			}else if(fabs(g3 - g1) <= t && fabs(g3 - g2) <= t){

				printf("%.*lf\n", 1, max(g3, max(g1, g2)));
			}else{
				double tmp = fabs(g3 - g1) < fabs(g3 - g2) ? ((g3 + g1) / 2.0) : ((g3 + g2) / 2.0);

				printf("%.*lf\n", 1, tmp);
			}
		}
	}
	return 0;

}