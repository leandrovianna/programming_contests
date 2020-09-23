// Codeforces - Buying Torches - 1418A
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  int64_t x, y, k;
  cin >> t;

  while (t--) {
    cin >> x >> y >> k;

    int64_t need = k * (y+1) - 1;
    int64_t ans = (need + (x-1) - 1) / (x-1) + k;
    cout << ans << "\n";
  }
  return 0;
}
