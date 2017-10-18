#include <iostream>
using namespace std;

int main() {
	const int N = 500;
	int n, k, a[N], b[N], s, stotal = 0;
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	b[0] = a[0];
	for (int i = 1; i < n; i++) {
		s = k - (b[i-1] + a[i]);
		if (s <= 0) {
			b[i] = a[i];
		} else {
			stotal += s;
			b[i] = a[i] + s;
		}
	}

	cout << stotal << endl;
	for (int i = 0; i < n; i++) {
		cout << b[i];
		if (i != n-1)
			cout << ' ';
	}
	cout << endl;
	return 0;
}
