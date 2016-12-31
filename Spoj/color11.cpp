#include <iostream>
using namespace std;

const int N = 200, M = 200;
const int T = 8;
const int Y[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int X[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int comp[N][M];

void dfs(int g[][M], const int n, const int m, const int i, const int j) {

	// executar dfs para toda a vizinhança de 8		
	for (int x = 0; x < T; x++) {
		for (int y = 0; y < T; y++) {
			int x0 = i + X[x];
			int y0 = j + Y[y];

			if (x0 < 0 || x0 >= n || y0 < 0 || y0 >= m)
				continue;

			if (!g[x0][y0] && comp[x0][y0] == -1) {
				comp[x0][y0] = comp[i][j];
				dfs(g, n, m, x0, y0);
			}
		}
	}
}

int main() {
	int g[N][M], n, m, x, y, k, l, c, qtd = 0;

	cin >> n >> m >> x >> y >> k;

	for (int r = 0; r < n; r++)
		for (int h = 0; h < m; h++) {
			comp[r][h] = -1;
			g[r][h] = 0;
		}

	for (int i = 0; i < k; i++) {
		cin >> l >> c;
		c--;
		g[n-l][c] = 1;
		comp[n-l][c] = 1;
	}

	x = n - x;
	y--;
	comp[x][y] = 2;
	g[x][y] = 1;

	dfs(g, n, m, x, y);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// cout << comp[i][j] << '\t';
			if (comp[i][j] == 2)
				qtd++;
		}
		// cout << endl;
	}

	cout << qtd << endl;
}
