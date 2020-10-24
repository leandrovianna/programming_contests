// Codeforces - Palindromic Paths - 1366C
#include <bits/stdc++.h>
using namespace std;

const int N = 70;
int c[N][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;

    for (int d = 0; d < N; d++) {
      c[d][0] = c[d][1] = 0;
    }

    int len = n+m-1;

    for (int i = 0, x, d; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> x;

        if (len % 2 != 0 && i+j == len/2)
          continue;

        if (i+j < len/2)
          d = abs(i + j);
        else
          d = abs((n - 1 - i) + (m - 1 - j));

        c[d][x]++;
      }
    }

    int ans = 0;
    for (int d = 0; d < N; d++) {
      ans += min(c[d][0], c[d][1]);
    }

    cout << ans << "\n";
  }
  return 0;
}
