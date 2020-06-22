#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	double l, k, t1, t2, h, f1, f2;

	cin >> l >> k >> t1 >> t2 >> h;
	
	if (h < l)
		f1 = f2 = h;
	else {
		double a = t1;
		double b = - (k*t1 + k*t2 + h);
		double c = (k * l);

		double delta = (b * b) - 4 * a * c;
		double r = (- b + sqrt(delta)) / (2 * a);

		f2 = r * t1;
		
		if (h > l)
			f1 = f2;
		else
			f1 = l;
	}
	
	cout << fixed << setprecision(9);
	cout << f1 << " " << f2 << endl;
	return 0;
}
