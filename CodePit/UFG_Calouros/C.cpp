#include <iostream>
#include <cstring>
using namespace std;

#define N 10010

long long dp[N];

long long solve(int i, int v[], int n) {
	if (i >= n) return 0;
	if (dp[i] != -1) return dp[i];
	
	return dp[i] = max(v[i] + solve(i+2, v, n),
					solve(i+1, v, n));
}

int main() {
	int t, n, v[N];
	
	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		memset(dp, -1, sizeof(dp));

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> v[i];

		cout << "Case " << ti+1 << ": " << solve(0, v, n) << endl;
	}
	return 0;
}
