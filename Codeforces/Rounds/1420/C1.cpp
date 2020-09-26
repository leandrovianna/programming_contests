// Codeforces - Pokemon Army (easy version) - 1420C1
#include <bits/stdc++.h>
using namespace std;

const int N = 300100;
int n;
int64_t a[N], dp[N][2];

int64_t solve(int i, int p) {
  if (i == n)
    return 0;

  int64_t &ans = dp[i][p];
  if (ans != -1) return ans;

  int delta = (p == 0 ? 1 : -1);

  ans = solve(i+1, p);
  ans = max(ans, delta * a[i] + solve(i+1, 1 - p));

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, q;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << "\n";
  }
  return 0;
}
