#include <iostream>
using namespace std;

#define N 20

int main() {
	int m[N][N], t, k;
	char c;
	bool beautiful, graceful;

	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		cin >> k;
		graceful = beautiful = true;

		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				cin >> c;
				m[i][j] = '0' - c;
			}
		}

		for (int i = 0; i < k/2; i++) {
			for (int j = 0; j < k; j++) {
				if (m[i][j] != m[k-1-i][j]) {
					beautiful = false;
				}
			}
		}

		for (int j = 0; j < k/2; j++) {
			for (int i = 0; i < k; i++) {
				if (m[i][j] != m[i][k-1-j]) {
					graceful = false;
				}
			}
		}

		if (graceful && beautiful)
			cout << "Magnificent" << endl;
		else if (graceful)
			cout << "Graceful" << endl;
		else if (beautiful)
			cout << "Beautiful" << endl;
		else
			cout << "Useless" << endl;

	}
	return 0;
}
