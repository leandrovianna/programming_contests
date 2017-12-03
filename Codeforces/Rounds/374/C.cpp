//Codeforces - Inna and Dima - 374C
#include <bits/stdc++.h>
using namespace std;

const int N = 1'005;
char grid[N][N];
int visited[N][N];
const int I[] = {-1, +0, +1, +0};
const int J[] = {+0, +1, +0, -1};
// const int INF = 1'000'000'000;

int ans = 0;

char next(char at) {
	if (at == 'D') return 'I';
	else if (at == 'I') return 'M';
	else if (at == 'M') return 'A';
	else if (at == 'A') return 'D';
	else return 'O';
}

bool dfs(int i, int j, int vv) {
	if (visited[i][j] != vv) {
		visited[i][j] = vv;

		if (grid[i][j] == 'A')
			ans++;

		for (int k = 0; k < 4; k++) {
			int di = i + I[k];
			int dj = j + J[k];

			if (0 <= di && di < N && 0 <= dj && dj < N) {
				if (grid[di][dj] == next(grid[i][j])) {
					cout << "-> " << grid[di][dj] << endl;
					if (!dfs(di, dj, vv))
						return false;
				}
			}
		}

		cout << "<-\n";
		return true;
	} else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, m, v = 1;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'D') {
				if (!dfs(i, j, v))
					return cout << "Poor Inna!\n", 0;
			}
		}
	}

	if (ans == 0)
		cout << "Poor Dima!\n";
	else
		cout << ans << endl;
	
	return 0;
}
