// Codeforces - Stairs - 1419B
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  int64_t x;
  cin >> t;

  while (t--) {
    cin >> x;

    int ans = 0;

    for (int k = 1; k < 32; k++) {
      int64_t beta = (1LL << k) - 1;
      beta = (beta * (beta+1)) / 2;

      if (x >= beta) {
        x -= beta;
        ans++;
      } else break;
    }

    cout << ans << "\n";
  }
  return 0;
}
