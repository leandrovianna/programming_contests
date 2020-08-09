// UVa - Philip J. Fry Problem - 12324
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int dp[N][N], t[N], b[N];
int n;

int solve(int i, int j) {
  if (i == n)
    return 0;

  if (dp[i][j] != -1) return dp[i][j];

  int &ans = dp[i][j];
  ans = solve(i+1, min(n, j + b[i])) + t[i];
  if (j > 0)
    ans = min(ans, solve(i+1, min(n, j - 1 + b[i])) + t[i] / 2);
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> t[i] >> b[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << "\n";
  }

  return 0;
}
