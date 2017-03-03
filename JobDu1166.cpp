#include<stdio.h>
#include<stdlib.h>


double fun(double y, double x)
{
	return y * 2 / 3.0 + x / (3 * y * y);
}

int main()
{
	int n;
	double x, y;
	while(scanf("%lf %d",&x,&n)!=EOF)
	{
		y = x;
		for(int i = 0; i< n; ++i){
			y = fun(y, x);
		}
		printf("%.6lf\n", y);
	}
	return 0;
}