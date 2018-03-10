//CodePit - Treats for the cows - H
#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 2100;
int v[N];
int dp[N][N], used[N][N], vis = 1;

int solve(int l, int r) {
	// cout << l << " " << r << endl;
	if (l > r) return 0;
	if (l == r)
		return (n - r + l) * v[l];

	if (used[l][r] == vis)
		return dp[l][r];
	used[l][r] = vis;

	int &ans = dp[l][r];

	ans = max(solve(l+1, r) + (n - r + l) * v[l],
			solve(l, r-1) + (n - r + l) * v[r]);

	return ans;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	cout << solve(0, n-1) << endl;

	return 0;
}
