#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

typedef pair<long, long> ll;
typedef vector<ll> vll;

#define N 18
#define S (1<<N)

#define NINF (-(i32)(1e9))

/* bitmask */
#define biton(n,p) ((n) | (1<<(p)))
#define bitoff(n,p) ((n) & ~(1<<(p)))
#define checkbit(n,p) ((n) & (1<<(p)))

i32 dp[N][S];

i32 solve(i16 g[][N], int i, int conjS, int d, int n) {
	//base case: g(i, ConjVazio) = w(i, d)
	if (i == d || !checkbit(conjS, d)) {
		return dp[i][conjS] = (i == d) ? 0 : NINF;
	}
	else if (dp[i][conjS] != -1) {
		return dp[i][conjS];
	}
	else {
		i32 r = NINF;
		for (int j = 0; j < n; j++) {
			if (checkbit(conjS, j) && g[i][j] > 0) {
				r = max(r, g[i][j] + solve(g, j, bitoff(conjS, j), d, n));
			}
		}

		return dp[i][conjS] = r;
	}
}

void dfs(i16 g[][N], const int v, const int n, int *bitmask) {
	for (int i = 0; i < n; i++) {
		if (!checkbit(*bitmask, i) && g[v][i] > 0) {
			*bitmask = biton(*bitmask, i);
			dfs(g, i, n, bitmask);
		}
	}
}

int main() {
	i16 g[N][N];
	int n, m, from, to, weight;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		memset(dp[i], -1, sizeof(dp[i]));
		memset(g[i], 0, sizeof(g[i]));
	}

	for (int i = 0; i < m; i++) {
		cin >> from >> to >> weight;
		g[from][to] = weight;
	}

	int conjS = 0;
	dfs(g, 0, n, &conjS);
	conjS = bitoff(conjS, 0);

	cout << solve(g, 0, conjS, n-1, n) << endl;
	return 0;
}
