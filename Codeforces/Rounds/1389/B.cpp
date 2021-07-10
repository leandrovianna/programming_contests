// Codeforces - Array Walk - 1389B
#include <bits/stdc++.h>
using namespace std;

int n, k, z;
const int N = 100100, Z = 6;
int a[N];
int dp[N][Z][2], used[N][Z][2], test = 0;

int solve(int sr, int sl, int fromLeft) {
  int i = sr - sl;

  if (sr + sl == k)
    return a[i];

  int &ans = dp[sr][sl][fromLeft];

  if (used[sr][sl][fromLeft] == test)
    return ans;
  used[sr][sl][fromLeft] = test;

  // go right
  ans = a[i] + solve(sr+1, sl, 0);

  // go left
  if (i > 0 && fromLeft == 0 && sl < z) {
    ans = max(ans, a[i] + solve(sr, sl+1, 1));
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
    cin >> n >> k >> z;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    test++;
    cout << solve(0, 0, 0) << "\n";
  }

  return 0;
}
