//CodePit - Lucro - F
//URI - Lucro - 1310
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n, c;
int d[N], dp[N][2], used[N][2], vis = 1;

int solve(int i, int j) {
	if (i >= n)
		return 0;

	if (used[i][j] == vis) return dp[i][j];
	used[i][j] = vis;

	if (j == 1) {
		dp[i][j] = max(0, (d[i] - c) + solve(i + 1, 1));
	} else {
		dp[i][j] = max(solve(i + 1, 0), (d[i] - c) + solve(i + 1, 1));
	}

	// cout << i << ", " << j << " = " << dp[i][j] << endl;

	return dp[i][j];
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> c) {
		for (int i = 0; i < n; i++)
			cin >> d[i];

		cout << solve(0, 0) << endl;
		vis++;
	}
	return 0;
}
