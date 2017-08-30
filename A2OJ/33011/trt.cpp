//SPOJ - TRT
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

const int N = 2010;
int n, v[N], dp[N][N];

int solve(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];
	if (i > j) return dp[i][j] = 0;
	if (i == j) return dp[i][j] = v[i] * n;

	int day = n - (j-i);

	return dp[i][j] = max(v[i] * day + solve(i+1, j),
						v[j] * day + solve(i, j-1));
}

int main() {
	ios::sync_with_stdio(false);
		
	cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i];

	memset(dp, -1, sizeof(dp));

	cout << solve(0, n-1) << endl;
	return 0;
}
