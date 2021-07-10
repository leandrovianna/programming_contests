// Spoj - Hotels Along the Croatian Coast - HOTELS
#include <bits/stdc++.h>
using namespace std;

const int N = 300100;
int64_t h[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  int64_t m;

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  int p1 = 0, p2 = 0;
  int64_t sum = h[0], ans = 0;
  while (p2 < n) {
    if (sum <= m) {
      ans = max(ans, sum);

      p2++;
      sum += h[p2];
    } else {
      if (p1 < p2) {
        sum -= h[p1];
        p1++;
      } else {
        p2++;
        sum += h[p2];
      }
    }
  }

  cout << ans << "\n";
  return 0;
}
