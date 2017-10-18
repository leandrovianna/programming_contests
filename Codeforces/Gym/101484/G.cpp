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

const int I = 26, J = 26, K = 1e4+10;

int dp[I][J][K], m[I][J];

int solve(int i, int j, int k) {
	// cout << "(" << i << "," << j << ") -> ";
	if (k == 1) {
		return m[i][j];
	}

	int &ans = dp[i][j][k];

	if (ans != -1) return ans;

	ans = 1e9;
	for (int x = 0; x < I; x++) {
		ans = min(ans, m[i][j] + solve(j, x, k-1));
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	int a, k;

	cin >> k;
	for (int i = 0; i < I; i++)
		for (int j = 0; j < J; j++)
			cin >> m[i][j];

	for (int i = 0; i < I; i++)
		for (int j = 0; j < J; j++)
			memset(dp[i][j], -1, sizeof(dp[i][j]));

	a = 1e9;
	for (int i = 0; i < I; i++)
		for (int j = 0; j < J; j++)
			a = min(a, solve(i, j, k-1));

	cout << a << endl;

	return 0;
}
