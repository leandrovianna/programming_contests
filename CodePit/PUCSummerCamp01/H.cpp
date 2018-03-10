//Puc Summer Camp 2018
//URI - Stock Market - 1932
#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100100;
int n, c;
int cot[N];
int dp[N][2];

int solve(int i, bool comprei) {
	if (i == n-1) {
		if (comprei)
			return cot[i];
		else
			return 0;
	}

	int &ans = dp[i][comprei];

	if (ans != -1)
		return ans;

	ans = solve(i+1, comprei);

	if (comprei) {
		ans = max(ans, cot[i] + solve(i+1, false));
	} else {
		ans = max(ans, - cot[i] - c + solve(i+1, true));
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> cot[i];
	cout << solve(0, false) << endl;

	return 0;
}
