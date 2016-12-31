#include <iostream>
using namespace std;

bool is_happy(int* v, int n, int i) {
	return (i != 0 && v[i-1] == v[i]) 
		|| (i != n-1 && v[i+1] == v[i]);
}

int main() {
	int g, n, b[110];
	int v[50];
	cin >> g;
	for (int gi = 0; gi < g; gi++) {
		cin >> n;

		for (int i = 0; i < 50; i++) v[i] = 0;

		for (int ni = 0; ni < n; ni++) {
			char c;
			cin >> c;
			if (c == '_') {
				b[ni] = 0;
				v[0]++;
			}
			else {
				b[ni] = c - 'A' + 1;
				v[b[ni]]++;
			}
		}

		int i;
		for (i = 1; i <= 26; i++) {
			if (v[i] == 1) {
				cout << "NO" << endl;
				break;
				// No pairs - NO
			}
		}
		if (i > 26) {
			if (v[0]) {
				cout << "YES" << endl;
				//Pairs and empty cells - YES
			} else {
				//Pairs and not empty cells - Depend
				int k;
				for (k = 0; k < n; k++) {
					if (b[k] && !is_happy(b, n, k)) {
						cout << "NO" << endl;
						break;
					}
				}
				if (k == n) cout << "YES" << endl;
			}
		}
	}
	return 0;
}
