// Codeforces - Subset Mex - 1406A
#include <bits/stdc++.h>
using namespace std;

const int D = 110;
int cnt[D];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n;
  cin >> t;
  while (t--) {
    fill(cnt, cnt+D, 0);
    cin >> n;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      cnt[x]++;
    }

    int ans = 0;
    for (int x = 0; x < D; x++) {
      if (cnt[x] == 0) {
        ans += x;
        break;
      }
    }

    for (int x = 0; x < D; x++) {
      if (cnt[x] <= 1) {
        ans += x;
        break;
      }
    }

    cout << ans << "\n";
  }
  return 0;
}
