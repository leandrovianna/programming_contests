#include <iostream>
using namespace std;

int main() {
	const int N = 110;
	int n, sum = 0;
	int a[N], deleted[N];

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
		deleted[i] = 0;
	}

	int value = sum / (n / 2);

	for (int i = 0; i < n-1; i++) {
		if (deleted[i]) continue;

		for (int j = i+1; j < n; j++) {
			if (deleted[j]) continue;
			if (a[i] + a[j] == value) {
				cout << i+1 << ' ' << j+1 << endl;
				deleted[i] = deleted[j] = 1;
				break;
			}
		}
	}

	return 0;
}
