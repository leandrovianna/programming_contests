//CodePit - Again Palindrome - J
//UVa - Again Palindrome - 10617
#include <bits/stdc++.h>
using namespace std;

string s;
int n;
const int N = 80;
int64_t dp[N][N];
int64_t used[N][N], vis = 1LL;

int64_t solve(int l, int r) {
	if (l > r) return 0;
	if (l == r) return 1;

	if (used[l][r] == vis) return dp[l][r];
	used[l][r] = vis;

	int64_t &ans = dp[l][r];

	ans = solve(l+1, r) + solve(l, r-1) - solve(l+1, r-1);

	if (s[l] == s[r]) {
		ans += 1 + solve(l+1, r-1);
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--) {
		cin >> s;
		cout << solve(0, s.size()-1) << endl;
		vis++;
	}

	return 0;
}
