#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	double a, x, a1, a2, a3;

	cout << fixed << setprecision(3);

	while (cin >> a) {

		if (a != 0) {
			x = a / 2.0;
			//a3 -> integral a^2 - sqrt(a^2 - x^2) de 0 a a/2
			a3 = 8 * (a * x - (a * a / 2) * asin(x / a) 
				- (x * sqrt(a*a - x*x)) / 2.0);
			//a2 -> integral a^2 - sqrt(a^2 - x^2) de 0 a a
			a2 = 4 * (a * a - (a * a / 2) * (M_PI / 2.0) - a3 / 2); 
			a1 = a * a - a2 - a3;
		} else {
			a1 = a2 = a3 = 0;
		}

		cout << a1 << " " << a2 << " " << a3 << endl;
	}
	return 0;
}
