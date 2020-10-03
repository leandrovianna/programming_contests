// Codeforces - Maximum Product - 1406B
#include <bits/stdc++.h>
using namespace std;

const int64_t inf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n;
  cin >> t;
  while (t--) {
    vector<int64_t> pos, neg;

    cin >> n;
    for (int i = 0, x; i < n; i++) {
      cin >> x;

      if (x >= 0) {
        pos.push_back(x);
      } else if (x < 0) {
        neg.push_back(x);
      }
    }
    sort(pos.begin(), pos.end());
    reverse(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    int m = pos.size(), k = neg.size();
    int64_t ans = -inf;

    for (int q = 0; q <= 5; q++) {
      if (m < q || k < 5-q)
        continue;
      int64_t y = 1;
      for (int i = 0; i < q; i++) {
        y *= pos[i];
      }
      for (int i = 0; i < 5-q; i++) {
        y *= neg[i];
      }
      ans = max(ans, y);
      y = 1;
      for (int i = 0; i < q; i++) {
        y *= pos[i];
      }
      for (int i = 0; i < 5-q; i++) {
        y *= neg[k-1-i];
      }
      ans = max(ans, y);
    }

    cout << ans << "\n";
  }

  return 0;
}
