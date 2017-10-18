#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int main() {
	string s;
	cin >> s;

	int dp[N], ans = 1;
	for (int i = 0; i < s.size(); i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (s[j] < s[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}

	cout << 26 - ans << endl;
	return 0;
}
