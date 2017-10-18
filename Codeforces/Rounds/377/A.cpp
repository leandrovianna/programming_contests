//After contests - Accepted
#include <iostream>
#include <cstring>
using namespace std;

#define MAX 500
#define EMPTY '.'
#define WALL '#'
#define REPLACEMENT 'X'

const int I[] = {0, -1, 0, 1};
const int J[] = {-1, 0, 1, 0};

char maze[MAX][MAX];
int comp[MAX][MAX];
int visitCells = 0;

void dfs(int i, int j, int n, int m, int limit) {
	visitCells++;

	if (visitCells > limit) {
		maze[i][j] = REPLACEMENT;
	}

	for (int x = 0; x < 4; x++) {
		int i0 = i + I[x], j0 = j + J[x];

		if (i0 < 0 || i0 > n-1 
				|| j0 < 0 || j0 > m-1)
			continue;

		if (maze[i0][j0] == EMPTY && comp[i0][j0] == -1) {
			comp[i0][j0] = comp[i][j];
			dfs(i0, j0, n, m, limit);
		}
	}
}

void solve(int n, int m, int k, int s) {
	for (int i = 0; i < n; i++)	{
		memset(comp[i], -1, sizeof(comp[i]));
	}

	for (int i = 0; i < n; i++)	
		for (int j = 0; j < m; j++)
			if (maze[i][j] == EMPTY && comp[i][j] == -1) {
				comp[i][j] = 1;
				dfs(i, j, n, m, s-k);
				break;
			}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (comp[i][j] == -1 && maze[i][j] == EMPTY)
				maze[i][j] = REPLACEMENT;

}

int main() {
	int n, m, k, s = 0;
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == EMPTY)
				s++;
		}

	solve(n, m, k, s);

	for (int i = 0; i < n; i++, cout << endl)
		for (int j = 0; j < m; j++)
			cout << maze[i][j];
	return 0;
}
