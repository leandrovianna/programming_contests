#include <iostream>
using namespace std;

const int M = 5;

bool test(char c, char p, int* q) {
	if (c == p) (*q)++;
	else *q = 0;
	
	if (*q == 4) return true;
	else return false;
}

bool win(char grid[][M], int x, int y, char p) {
	
	grid[x][y] = p;

	int q = 0;
	for (int j = 0; j < M; j++) {
		if (test(grid[x][j], p, &q))
			return true;
	}

	q = 0;
	for (int i = 0; i < M; i++) {
		if (test(grid[i][y], p, &q))
			return true;
	}

	q = 0;
	for (int i = 0; i < M; i++) {
		int j = i - x + y;
		if (0 <= j && j < M) {
			if (test(grid[i][j], p, &q))
				return true;
		}
	}

	q = 0;
	for (int i = 0; i < M; i++) {
		int j = x + y - i;
		if (0 <= j && j < M) {
			if (test(grid[i][j], p, &q))
				return true;
		}
	}
	
	grid[x][y] = '*';
	return false;
}

int main() {
	char grid[M][M];
	string s;
	int l;

	l = 0;
	while (getline(cin, s) && s != "Finished") {
		if (s == "") continue;

		for (int k = 0; k < M; k++)
			grid[l][k] = s[k*2];
		l++;

		if (l == M) {
			l = 0;
			int r = 1;

			for (int i = 0; i < M; i++) {
				for (int j = 0; j < M; j++) {
					if (grid[i][j] == '*') {
						r = i * M + j + 1;
						if (!win(grid, i, j, 'O') && !win(grid, i, j, 'X')) {
							i = M;
							break;
						}
					}
				}
			}

			cout << r << endl;
		}
	}

	return 0;
}
