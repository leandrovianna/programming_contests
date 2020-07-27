// Codeforces - Delayed Work - 101615L 
#include <bits/stdc++.h>
using namespace std;

double calc(int64_t k, int64_t p, int64_t x, int64_t m) {
  return m * x + static_cast<double>(k) / m * p;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int64_t k, p, x;
  cin >> k >> p >> x;

  int64_t hi = 1e9, lo = 1, m1, m2;
  double x1, x2;

  while (hi - lo >= 3) {
    m1 = lo + (hi - lo) / 3;
    x1 = calc(k, p, x, m1);
    m2 = hi - (hi - lo) / 3;
    x2 = calc(k, p, x, m2);

    if (x1 <= x2) {
      hi = m2;
    } else {
      lo = m1;
    }
  }

  double ans = numeric_limits<double>::max();
  for (int64_t m = lo; m <= hi; m++)
    ans = min(ans, calc(k, p, x, m));

  cout << fixed << setprecision(3);
  cout << ans << "\n";
  return 0;
}
