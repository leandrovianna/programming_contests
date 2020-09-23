// Codeforces - Mortal Kombat Tower - 1418C
#include <bits/stdc++.h>
using namespace std;

const int N = 200100, inf = 1e9;
int n, a[N], dp[N][2];

int solve(int i, int turn) {
  if (i == n)
    return 0;

  if (dp[i][turn] != -1)
    return dp[i][turn];

  int &ans = dp[i][turn];
  ans = inf;

  // kill one boss
  int skip_point = (turn == 0 ? a[i] : 0);
  ans = min(ans, skip_point + solve(i+1, 1 - turn));

  // kill two bosses
  if (i < n-1) {
    skip_point = (turn == 0 ? a[i] + a[i+1] : 0);
    ans = min(ans, skip_point + solve(i+2, 1 - turn));
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << "\n";
  }
  return 0;
}
