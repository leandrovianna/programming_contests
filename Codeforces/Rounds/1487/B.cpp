// Codeforces - Cat Cycle - 1487B
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n, k;

  cin >> t;
  while (t--) {
    cin >> n >> k;

    int ans = 0;

    if (n % 2 == 0) {
      ans = (k-1) % n + 1;
    } else {
      int cycle = n / 2;
      if (k <= cycle) {
        ans = k;
      } else {
        int inc = 1 + (k - cycle - 1) / cycle;
        ans = (k-1+inc) % n + 1;
      }
    }

    cout << ans << "\n";
  }
  return 0;
}
