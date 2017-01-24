//Accepted - 100 points
#include <iostream>
#include <algorithm>
using namespace std;

#define N 10000

int main() {
	int n, m, a[N];

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	long total = 0;
	int ant = 0;
	for (int i = 0; i < n; i++) {
		int m1 = min(m - a[i], a[i]);
		int m2 = max(m - a[i], a[i]);

		if (m1 >= ant) {
			total += m1;
			ant = m1;
		} else if (m2 >= ant) {
			total += m2;
			ant = m2;
		} else {
			cout << -1 << endl;
			return 0;
		}
	}

	cout << total << endl;
	return 0;
}
