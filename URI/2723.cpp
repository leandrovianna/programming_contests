// URI - Equilibrando Presentes - 2723
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t, n;
	int64_t a, b, p;
	bool naodeu;

	cin >> t;
	while (t--) {
		cin >> n;

		naodeu = false;
		a = b = 0;

		for (int i = 0; i < n; i++) {
			cin >> p;

			if (abs(a + p - b) <= 5) {
				a += p;
			} else if (abs(b + p - a) <= 5) {
				b += p;
			} else {
				naodeu = true;
			}
		}

		if (naodeu)
			cout << "Ho Ho Ho!" << endl;
		else
			cout << "Feliz Natal!" << endl;
	}

	return 0;
}
