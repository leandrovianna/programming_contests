// Codeforces - Rock and Lever - 1420B
#include <bits/stdc++.h>
using namespace std;

const int B = 32;
int cnt[B];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n;
  cin >> t;
  while (t--) {
    fill(cnt, cnt+B, 0);
    cin >> n;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      for (int j = 30; j >= 0; j--) {
        if (x & (1 << j)) {
          cnt[j]++;
          break;
        }
      }
    }

    int64_t ans = 0;
    for (int j = 0; j < B; j++) {
      int64_t x = cnt[j];
      ans += (x * (x-1)) / 2;
    }
    cout << ans << "\n";
  }

  return 0;
}
