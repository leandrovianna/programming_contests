//CodeChef - Chef and His Cake - DEC17 GIT01
#include <bits/stdc++.h>
using namespace std;

// const int I[] = {+0, +1, +0, -1};
// const int J[] = {-1, +0, +1, +0};
// const int I[] = {-1, +1, -1, +1};
// const int J[] = {-1, +1, +1, -1};

int cost(char from) {
	return from == 'R' ? 5 : 3;
}

char change(char from) {
	return from == 'R' ? 'G' : 'R';
}

int main() {
	ios::sync_with_stdio(false);
	const int N = 110;
	int n, m, t;
	char grid[N][N], g1[N][N], g2[N][N];
	
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
				g1[i][j] = (i % 2 != j % 2 ? 'R' : 'G');
				g2[i][j] = change(g1[i][j]);
			}
		}

		int ans1 = 0, ans2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (g1[i][j] != grid[i][j])
					ans1 += cost(grid[i][j]);
				if (g2[i][j] != grid[i][j])
					ans2 += cost(grid[i][j]);
			}
			cout << endl;
		}
		cout << min(ans1, ans2) << endl;
	}

	return 0;
}
