// YES - 100 points
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long i32;
typedef long long i64;

#define N 1001000
#define K 1010

i32 dp[K], a[N];

i32 solve(i32 n, i32 k, i32 m) {
	if (dp[k] != -1) return dp[k];
	else {
		i32 s = 0;
		for (int i = 0; i < n; i++) {
			s = (s % m + (a[i] * solve(n, k-i-1, m) % m) % m) % m;
		}
		return dp[k] = s % m;
	}
}

int main() {
	i32 n, k, m, x;

	cin >> n >> k >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	memset(dp, -1, sizeof(dp));

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		dp[i] = x % m;
	}

	cout << solve(n, k, m) % m << endl;
	return 0;
}
