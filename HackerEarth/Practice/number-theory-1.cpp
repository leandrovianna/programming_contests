#include <iostream>
using namespace std;

int d, x, y;

void extendedEuclides(long a, long b) {
	if (b == 0) {
		d = a;
		x = 1;
		y = 0;
	} else {
		extendedEuclides(b, a%b);
		long t = x;
		x = y;
		y = t - (a / b) * y;
	}
}

long modInverse(long n, long m) {
	extendedEuclides(n, m);
	// x can be negative
	return (x % m + m) % m;
}

long modExp(long x, long n, long m) {
	if (n == 0)
		return 1;
	else if (n % 2 == 0)
		return modExp((x*x)%m, n/2, m);
	else
		return (x * modExp((x*x)%m, (n-1)/2, m)) % m;
}

int main() {
	long a, b, c, m;

	cin >> a >> b >> c >> m;

	cout << (modExp(a, b, m) * modInverse(c, m)) % m << endl;
	return 0;
}
