#include <iostream>
using namespace std;

int factorial (int n) {
	if (n == 1 || n == 0) return 1;
	else return n * factorial(n-1);
}

int main() {
	int m, n, i, g, s, fqtd;
	
	cin >> n;

	i = 1;
	g = n;
	fqtd = 0;

	while (g > 0) {
		m = factorial(i);
		if (m > g) {
			int f = factorial(i-1);
			g -= f;
			i = 1;
			fqtd++;
		}
		else {
			i++;
		}
	}

	cout << fqtd << endl;
	return 0;
}
