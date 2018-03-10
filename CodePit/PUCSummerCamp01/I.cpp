//Puc Summer Camp 2018
//URI - Andre e os Mentos - 1775
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, v[N];
int dp[N][N], used[N][N], vis = 1;

int f(int l, int r) {
	if (l > r)
		return 0;
	if (l == r)
		return 1;

	int &ans = dp[l][r];

	if (used[l][r] == vis)
		return ans;
	used[l][r] = vis;

	if (v[l] != v[r]) {
		ans = 1 + min(f(l+1, r), f(l, r-1));
	} else {
		ans = 1 + f(l+1, r-1);
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cout << "Caso #" << ti+1 << ": " << f(0, n-1) << endl;
		vis++;
	}

	return 0;
}
