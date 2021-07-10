// Codeforces - Good String - 1389C
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  string s;

  cin >> t;
  while (t--) {
    cin >> s;
    const int n = s.size();

    int ans = n;
    for (int d1 = 0; d1 < 10; d1++) {
      for (int d2 = 0; d2 < 10; d2++) {
        bool turn = true;
        int m = 0;

        for (int i = 0, d; i < n; i++) {
          d = turn ? d1 : d2;
          if (s[i] - '0' == d) {
            m++;
            turn = !turn;
          }
        }

        if (d1 != d2)
          m -= m % 2;
        ans = min(ans, n - m);
      }
    }

    cout << ans << "\n";
  }
  return 0;
}
