#include <iostream>
using namespace std;

int main() {
	int t, n;

	cin >> t;

	for (int ti = 0; ti < t; ti++) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (min(i, j) != 0 && max(i,j) != n-1) {
					cout << "J";
				}
				else {
					cout << "#";
				}
			}
			cout << endl;
		}

		if (ti != t-1)
			cout << endl;
	}
	return 0;
}
