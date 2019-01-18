#include <bits/stdc++.h>

using namespace std;

#define PI	acos(-1.0)

struct point{
	double x, y;
};

double DEG_to_RAD(double x){
	return (PI * x) / 180.0;
}

point rotate(point p, double theta){
	double rad = DEG_to_RAD(theta);
	return {p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad)};
}

double dist(point x, point y){
	return hypot(x.x - y.x, x.y - y.y);
}

double area(point x, point y, point z){
	double la = dist(x, y);
	double lb = dist(y, z);
	double lc = dist(x, z);
	double p = la + lb + lc;
	double s = 0.5 * p;

	return sqrt(s * (s - la) * (s - lb) * (s - lc));
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		double l, a;

		scanf("%lf %lf", &l, &a);

		point y = {0.0, 0.0};
		point x = {0.0, l};

		point z = rotate(x, a);
		// printf("%lf %lf\n", z.x, z.y);

		double ar = area(x, y, z);
		// printf("%lf\n", ar);

		double tot = PI * l * l;
		double have = (a / 360.0) * tot;
		// printf("%.2lf\n", have);

		printf("%.6lf\n", have - ar);
	}

	return 0;
}