#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <limits>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

typedef struct {
	int m, f, w;
} wave;

const int T = 1e6+10;

int max_time = 0;
int n;
wave waves[T];

int dp[T];

int solve(int t) {
	// cout << t << endl;
	if (t > max_time) return 0;

	if (dp[t] != -1) return dp[t];

	dp[t] = 0;
	dp[t] = max(dp[t], solve(t + 1));

	// cout << "*" << waves[t].m << endl;
	if (waves[t].m > 0)
		dp[t] = max(dp[t], waves[t].f + solve(t + waves[t].w));

	return dp[t];
}

int main() {
	ios::sync_with_stdio(false);
	int x;

	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		max_time = max(max_time, x);

		waves[x].m = x;
		cin >> waves[x].f >> waves[x].w;
	}

	cout << solve(0) << endl;
	return 0;
}
