//WA - 80 points
#include <iostream>
#include <cstring>
using namespace std;

#define N (1010)
#define MAX (1010)

int dp[MAX], a[N];

int recursion(int k, int n, int m) {
	if (dp[k] != -1)
		return dp[k];
	else {
		dp[k] = 0;
		for (int i = 1; i <= n; i++) {
			dp[k] += ((a[i] % m * recursion(k-i, n, m) % m) % m + m) % m;
		}
		dp[k] = dp[k] % m;
		return dp[k];
	}
}

int main() {
	int n, k, m;

	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		cin >> dp[i];
		dp[i] = dp[i] % m;
	}

	cout << recursion(k, n, m) << endl;
	return 0;
}
