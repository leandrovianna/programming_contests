#include <iostream>
using namespace std;

long gcd(long a, long b) { return b ? gcd(b, a%b) : a; }

int main() {
	const int N = 100100;
	long a[N], temp;
	int n, moves;

	cin >> n;
	temp = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		temp = gcd(temp, a[i]);
	}

	if (temp > 1) {
		cout << "YES" << endl << "0" << endl;
	} else {
		moves = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2) {
				if (i != 0 && a[i-1] % 2)
					moves++, a[i] = a[i-1] = 2;
				else if (i != n-1 && a[i+1] % 2)
					moves++, a[i] = a[i+1] = 2;
				else
					moves += 2, a[i] = 2;
			}
		}

		cout << "YES" << endl << moves << endl;
	}	
	return 0;
}
