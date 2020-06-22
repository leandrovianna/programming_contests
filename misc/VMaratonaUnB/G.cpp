#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, resto, j, i;
	
	int ti = 1;
	bool ok;
	while (cin >> n, n) {
		ok = false;
		for (i = 1; i * i < n; i++) {
			resto = n - (i * i);	

			j = sqrt(resto);
			if ((j * j) == resto) {
				ok = true;
				break;
			}
		}

		cout << "Caso " << ti << ": ";
		if (ok) {
			cout << j << " " << i << "\n";
		} else {
			cout << "metragem invalida\n";
		}

		ti++;
	}

	return 0;
}
