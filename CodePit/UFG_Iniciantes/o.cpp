#include <iostream>
using namespace std;

#define N 1000
#define M 1000

#define EMPTY '.'
#define WALL '#'
#define NEW_WALL 'X'

int nmaze[N][M], l0 = 0, limit;

void dfs(int t[][M], const int i, const int j, const int n, const int m) {
	int top = (i != 0 && t[i-1][j] == 1) ? 1 : 0;
	int left = (j != 0 && t[i][j-1] == 1) ? 1 : 0;
	int bottom = (i != n-1 && t[i+1][j] == 1) ? 1 : 0;
	int right = (j != m-1 && t[i][j+1] == 1) ? 1 : 0;

	if (l0 < limit) {
		nmaze[i][j] = 1;
		l0++;
	}

	if (top) {
		t[i-1][j] = t[i][j];
		dfs(t, i-1, j, n, m);
	}

	if (left) {
		t[i][j-1] = t[i][j];
		dfs(t, i, j-1, n, m);
	}		

	if (bottom) {
		t[i+1][j] = t[i][j];
		dfs(t, i+1, j, n, m);
	}

	if (right) {
		t[i][j+1] = t[i][j];
		dfs(t, i, j+1, n, m);
	}

}

int main() {
	int maze[N][M], n, m, k, s = 0;
	char ch;

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ch;
			maze[i][j] = (ch == EMPTY) ? 1 : 0;
			nmaze[i][j] = 0;
			if (maze[i][j])
				s++;
		}
	}

	limit = s - k;
	l0 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maze[i][j]) {
				maze[i][j] = 2;
				dfs(maze, i, j, n, m);
			}
		}
	}

	for (int i = 0, l = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maze[i][j]) {
				if (nmaze[i][j]) cout << EMPTY;
				else cout << NEW_WALL;
			}
			else cout << WALL;
		}
		cout << endl;
	}

	return 0;
}
