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

const int N = 1e4+10;
int n, k;
int imp[N];
vector<pair<int,int> > g[N];

int dfs(int v, int p) {
	int res = 0;
	for (auto &uw : g[v]) {
		int u = uw.first;

		if (u == p) continue;

		res += dfs(u, v);

		int tmp = (imp[u] + k - 1) / k;
		res += tmp * 2 * uw.second;
		imp[v] += imp[u];
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	int a, b, c;

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> imp[i];

	for (int i = 0; i < n-1; i++) {
		cin >> a >> b >> c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}

	cout << dfs(1, -1) << endl;

	return 0;
}
