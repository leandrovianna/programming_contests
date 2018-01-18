//Codeforces - Tic-Tac-Toe - 907B Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 9;
char grid[N][N];

int main() {
	ios::sync_with_stdio(false);
	int x, y;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}

	cin >> x >> y;

	x--;
	y--;
	int p, q;
	p = x % 3;
	q = y % 3;

	bool notempty = true;

	for (int i = p * 3; i < (p * 3 + 3); i++) {
		for (int j = q * 3; j < (q * 3 + 3); j++) {
			if (grid[i][j] == '.') {
				notempty = false;
				grid[i][j] = '!';
			}
		}
	}

	if (notempty) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (grid[i][j] == '.')
					grid[i][j] = '!';
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << grid[i][j];
			if (j % 3 == 2)
				cout << " ";
		}
		if (i % 3 == 2)
			cout << endl;
		cout << endl;
	}

	return 0;
}
