#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;
int memo[N];

int f(int x, int p) {
  if (x <= 1)
    return 1;
  else if (memo[x] != -1)
    return memo[x];
  else
    return memo[x] = 1 + f(p % x, p);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;

  cout << fixed << setprecision(10);

  int p;
  while (t--) {
    cin >> p;

    memset(memo, -1, sizeof(memo));
    int64_t total = 0;
    for (int x = 1; x <= p-1; x++) {
      total += f(x, p);
    }

    double ans = total;
    ans /= p-1;

    cout << ans << "\n";
  }

  return 0;
}
