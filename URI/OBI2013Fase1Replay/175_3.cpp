#include <iostream>
using namespace std;

const int C = 1e3;

void dfs(int m[][C], int comp[][C], int i, int j, int l, int c) {
	bool last = true;
	if (i != 0 && m[i-1][j] && comp[i-1][j] == -1) {
		comp[i-1][j] = comp[i][j];
		dfs(m, comp, i-1, j, l, c);
		last = false;
	}
	if (i != l-1 && m[i+1][j] && comp[i+1][j] == -1) {
		comp[i+1][j] = comp[i][j];
		dfs(m, comp, i+1, j, l, c);
		last = false;
	}
	if (j != 0 && m[i][j-1] && comp[i][j-1] == -1) {
		comp[i][j-1] = comp[i][j];
		dfs(m, comp, i, j-1, l, c);
		last = false;
	}
	if (j != c-1 && m[i][j+1] && comp[i][j+1] == -1) {
		comp[i][j+1] = comp[i][j];
		dfs(m, comp, i, j+1, l, c);
		last = false;
	}

	if (last)
		cout << i+1 << ' ' << j+1 << endl;
}

int main() {
	const int L = 1e3;
	int m[L][C], l, c, a, b, comp[L][C];

	cin >> l >> c;
	cin >> a >> b;
	a--;
	b--;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			cin >> m[i][j];
			comp[i][j] = -1;
		}
	}

	comp[a][b] = 1;
	dfs(m, comp, a, b, l, c);

	return 0;
}
