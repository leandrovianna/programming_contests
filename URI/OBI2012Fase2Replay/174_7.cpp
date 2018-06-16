#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	const int N = 1e5;
	int n, limit;
	unsigned long long c[N], k, a, b;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	cin >> k;

	limit = n;
	for (int i = 0; i < n; i++) {
		if (c[i] >= k) {
			limit = i;
			break;
		}
	}

	for (int i = 0; i < limit-1; i++) {
		b = k - c[i];
		if (binary_search(c+i, c+limit, b)) {
			a = c[i];
			b = k - a;
			break;
		}
	}

	cout << a << " " << b << endl;
	return 0;
}
