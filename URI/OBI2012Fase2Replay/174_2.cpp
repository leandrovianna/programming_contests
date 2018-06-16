#include <iostream>
using namespace std;

int main() {
	const int Y[] = {-1, 0, 1, 0};
	const int X[] = {0, -1, 0, 1};
	const int N = 1e3, M = 1e3;
	int a[N][M], n, m, qtd;	
	char ch;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ch;
			a[i][j] = (ch == '.') ? 0 : 1;
		}
	}

	qtd = 0;
	//todos na 1a linha e ultima linha
	//sao costa
	for (int i = 0; i < m; i++) {
		if (a[0][i]) qtd++;
		if (a[n-1][i]) qtd++;
	}

	for (int i = 1; i < n-1; i++) {
		for (int j = 0; j < m; j++) {
			if (!a[i][j]) continue;
			if (j == 0 || j == m-1) {
				qtd++;
				continue;
			}
			for (int k = 0; k < 4; k++) {
				int x0 = i + X[k];
				int y0 = j + Y[k];

				if (x0 < 0 || x0 >= n || y0 < 0 || y0 >= m)
					continue;

				if (!a[x0][y0]) {
					qtd++;
					break;
				}
			}
		}
	}

	cout << qtd << endl;
	return 0;
}
