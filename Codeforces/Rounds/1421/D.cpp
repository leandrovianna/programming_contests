// Codeforces - Hexagons - 1421D
#include <bits/stdc++.h>
using namespace std;

int64_t c[7];
int64_t sidemove(int p, int y) {
  if (p < y)
    return (y - p) * c[2];
  else
    return (p - y) * c[5];
}

int64_t calc(int m, int x, int y) {
  if (x > 0)
    return m * c[6] + (x - m) * c[1] + sidemove(x - m, y);
  else
    return m * c[3] + ((-x) - m) * c[4] + sidemove((-x) - m, y);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);


  int t, x, y;
  cin >> t;
  while (t--) {
    cin >> x >> y;

    for (int i = 1; i <= 6; i++)
      cin >> c[i];

    int r = abs(x), l = 0;
    while (r - l > 3) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;

        int f1 = calc(m1, x, y);
        int f2 = calc(m2, x, y);

        if (f1 > f2) l = m1;
        else r = m2;
    }

    int64_t cost = numeric_limits<int64_t>::max();
    for (int i = l; i <= r; i++) {
      cost = min(cost, calc(i, x, y));
    }
    cout << cost << "\n";
  }
  return 0;
}
