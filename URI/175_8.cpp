#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	const int N = 1e5;
	int n, k;
	int x[N];

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> x[i];

	sort(x, x+n);

	int minimo = 999999;
	for (int i = 0; i <= k; i++) {
		minimo = min(minimo, x[n-1-(k-i)] - x[i]);
	}

	cout << minimo << endl;
	return 0;
}
