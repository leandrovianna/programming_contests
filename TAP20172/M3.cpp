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

int main() {
	ios::sync_with_stdio(false);
	const int N = 60;
	int n, v[N], dp[N][2];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		dp[i][0] = dp[i][1] = 1;
	}

	int r = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
			if (v[j] > v[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
		}
		r = max(r, max(dp[i][0], dp[i][1]));
	}

	// for (int i = 0; i < n; i++)
	// 	cout << dp[i][0] << " " << dp[i][1] << endl;
	
	cout << r << endl;
	return 0;
}
