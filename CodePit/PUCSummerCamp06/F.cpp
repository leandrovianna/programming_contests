//CodePit - Longest Palindrome - F
//UVa - '' - 11151
#include <bits/stdc++.h>
using namespace std;

const int N = 1010, INF = 100000;
int dp[N][N];
int used[N][N], vis = 1;
string s;

int solve(int l, int r) {
	if (l > r) return 0;
	if (l == r) return 1;
	if (l == r - 1) return s[l] == s[r] ? 2 : 1;

	int &ans = dp[l][r];

	if (used[l][r] == vis)
		return ans;
	used[l][r] = vis;

	ans = 0;

	if (s[l] == s[r]) {
		ans = 2 + solve(l+1, r-1);
	} else {
		ans = max(solve(l+1, r), solve(l, r-1));
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	int t;

	cin >> t;
	cin.ignore();
	for (int ti = 0; ti < t; ti++) {
		getline(cin, s);

		vis++;
		cout << solve(0, s.size()-1) << endl;
	}

	return 0;
}
