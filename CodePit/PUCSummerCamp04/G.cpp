//CodePit - Cutting Sticks - G
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int INF = 1000000000;
int l, n;
int cuts[N];
int dp[N][N], used[N][N], vis = 1;

int solve(int left, int right) {
	if (left + 1 == right) return 0;

	if (used[left][right] == vis) return dp[left][right];
	used[left][right] = vis;

	int &ans = dp[left][right];
	ans = INF; // nota: nao esqueca de iniciar o valor da DP

	for (int i = left+1; i < right; i++) {
		ans = min(ans, solve(left, i) + solve(i, right)
				+ (cuts[right] - cuts[left]));
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);

	while (cin >> l, l) {
		cin >> n;
		cuts[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> cuts[i];
		}
		cuts[n+1] = l;

		cout << "The minimum cutting is " << solve(0, n+1) << "." << endl;
		vis++;
	}

	return 0;
}
