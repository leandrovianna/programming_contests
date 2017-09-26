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
	int s, d, p; //start time, duration, price
} order;

const int N = 1e4+10, T = 1e6+10;
order orders[T];
int n, max_time;

long long dp[T];
int used[T], used2[T];
int vis = 1;

long long solve(int t) {
	if (t > max_time) return 0;

	long long &ans = dp[t];

	if (used[t] == vis) return ans;
	used[t] = vis;

	ans = solve(t+1);

	if (used2[t] == vis)
		ans = max(ans, orders[t].p + solve(t + orders[t].d));

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	int t, x;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			cin >> orders[x].d >> orders[x].p;
			orders[x].s = x;
			used2[x] = vis;
			max_time = max(max_time, x);
		}

		cout << solve(0) << endl;
		vis++;
	}
	return 0;
}
