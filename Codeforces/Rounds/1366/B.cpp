// Codeforces - Shuffle - 1366
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n, x, m;

  cin >> t;
  while (t--) {
    cin >> n >> x >> m;

    int xl = x, xr = x;
    for (int i = 0, l, r; i < m; i++) {
      cin >> l >> r;

      if ((l <= xl && xl <= r) || (l <= xr && xr <= r)) {
        xl = min(l, xl);
        xr = max(r, xr);
      }
    }

    cout << xr - xl + 1 << "\n";
  }
  return 0;
}
