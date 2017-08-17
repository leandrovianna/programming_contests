#include <iostream>
using namespace std;

#define N 20

int main() {
	int t, n, m, c, res, min, max;
	int vol[N];

	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		res = 0;
		cin >> n >> m >> c;
		for (int i = 0; i < n; i++)
			cin >> vol[i];

		for (int i = 0; i < n-m+1; i++) {
			min = 10000;
			max = 0;
			// cout << "*vol[i] " << vol[i] << endl;
			for (int j = 0; j < m; j++) {
				if (vol[i+j] < min)
					min = vol[i+j];
				if (vol[i+j] > max)
					max = vol[i+j];
			}
			if (max - min <= c) {
				// cout << "*res++" << endl;
				res++;
			}
		}

		cout << res << endl;
	}
	return 0;
}
