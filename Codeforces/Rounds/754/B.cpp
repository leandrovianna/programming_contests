#include <iostream>
using namespace std;

#define N 4
#define W 3
#define C 'x'

bool test(char c, int *q) {
	if (c == C) (*q)++;
	else *q = 0;

	return *q == W;
}

bool win(char grid[][N], int x, int y) {
	int q = 0;

	grid[x][y] = C;

	for (int i = 0; i < N; i++) 
		if (test(grid[i][y], &q))
			return true;

	q = 0;
	for (int j = 0; j < N; j++)
		if (test(grid[x][j], &q))
			return true;

	q = 0;
	for (int i = 0; i < N; i++) {
		int j = i - x + y;
		if (0 <= j && j < N) {
			if (test(grid[i][j], &q))
				return true;
		}
	}

	q = 0;
	for (int i = 0; i < N; i++) {
		int j = x + y - i;
		if (0 <= j && j < N) {
			if (test(grid[i][j], &q))
				return true;
		}
	}

	grid[x][y] = '.';
	return false;
}

int main() {
	char grid[N][N];		

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> grid[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (grid[i][j] == '.' && win(grid, i, j)) {
				cout << "YES" << endl;
				return 0;
			}

	cout << "NO" << endl;
	return 0;
}
