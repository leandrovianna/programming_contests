//HackerRank - Matrix Land - WC35 4
#include <bits/stdc++.h>
using namespace std;

const int M  = 4*1e6+10;
const int L = 2;
int n, m;
int64_t a[M];
int64_t mpref[M], msuf[M];
int64_t pref[M];
int64_t dp[L][M];

//variaveis da seg tree
int h;
int64_t d[M];
int64_t t[2*M];
int N;

void clearTree() {
	memset(t, 0, 2 * N * sizeof(int64_t));
	memset(d, 0, 2 * N * sizeof(int64_t));
}

void apply(int p, int64_t value) {
  t[p] += value;
  if (p < N) d[p] += value;
}

void build(int p) {
  while (p > 1) p >>= 1, t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
}

void push(int p) {
  for (int s = h; s > 0; --s) {
    int i = p >> s;
    if (d[i] != 0) {
      apply(i<<1, d[i]);
      apply(i<<1|1, d[i]);
      d[i] = 0;
    }
  }
}

void inc(int l, int r, int64_t value) {
  l += N, r += N;
  int l0 = l, r0 = r;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) apply(l++, value);
    if (r&1) apply(--r, value);
  }
  build(l0);
  build(r0 - 1);
}

int query(int l, int r) {
  l += N, r += N;
  push(l);
  push(r - 1);
  int64_t res = numeric_limits<int64_t>::min();
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++]);
    if (r&1) res = max(t[--r], res);
  }
  return res;
}

void initSegTree(int size) {
	N = size+1;
	h = sizeof(int) * 8 - __builtin_clz(N);
}

void getMaxPrefix() {
	clearTree();
	for (int j = 1; j <= m; j++) {
		inc(j, m+1, a[j]);
	}
		
	for (int j = 1; j <= m; j++) {
		inc(j, m+1, -a[j]);
		mpref[j] = query(j, m+1);
	}
}

void getMaxSuffix() {
	clearTree();
	for (int j = m; j >= 1; j--) {
		inc(1, j+1, a[j]);
	}

	for (int j = m; j >= 1; j--) {
		inc(1, j+1, -a[j]);
		msuf[j] = query(1, j+1);
	}
}

void solve() {
	cin >> n >> m;
	initSegTree(m);
	int line = 0;

	for (int i = 1; i <= n; i++) {
		line = 1 - line;

		for (int j = 1; j <= m; j++) {
			cin >> a[j];
			pref[j] = pref[j-1] + a[j];
			mpref[j] = 0;
			msuf[j] = 0;
		}

		getMaxPrefix();
		getMaxSuffix();

		set<pair<int64_t, int> > haha;

		for (int k = 1; k <= m; k++)
			haha.insert({-dp[1-line][k], k});

		for (int j = 1; j <= m; j++) {
			dp[line][j] = dp[1-line][j] + a[j] + mpref[j] + msuf[j];

			int k;
			// int64_t prev = haha.begin()->first;
			int count = 0;
			for (auto &p : haha) {
				// if (p.first != prev) break;
				count++;

				if (count > m/2) break;

				k = p.second;

				if (k <= j)
					dp[line][j] = max(dp[line][j], dp[1-line][k] + (pref[j] - pref[k-1]) + mpref[j] + msuf[k]);

				if (k >= j)
					dp[line][j] = max(dp[line][j], dp[1-line][k] + (pref[k] - pref[j-1]) + mpref[k] + msuf[j]);
			}

			// cout << count << " " << prev << endl;

			// for (int k = j; k >= 1; k--) {
			// 	dp[line][j] = max(dp[line][j], dp[1-line][k] + (pref[j] - pref[k-1]) + mpref[j] + msuf[k]);
			// }
            //
			// for (int k = j; k <= m; k++) {
			// 	dp[line][j] = max(dp[line][j], dp[1-line][k] + (pref[k] - pref[j-1]) + mpref[k] + msuf[j]);
			// }
		}

        // for (int j = 0; j <= m; j++) {
        // 	cout << dp[line][j] << "\t\n"[j == m];
		// }
	}

	int64_t ans = numeric_limits<int64_t>::min();
	for (int i = 1; i <= m; i++) {
		ans = max(ans, dp[line][i]);
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
