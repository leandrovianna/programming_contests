// Codeforces Gym - Genta Game - 101778H
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
bool mark[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n, m, p;
  string s;
  char c;

  cin >> t;
  while (t--) {
    cin >> n >> m;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < n/2; i++) {
      mark[i] = s[i] == s[n-1-i];
      if (!mark[i])
        cnt++;
    }

    if (n % 2 != 0)
      mark[n/2] = true;

    int ans = 0;
    for (int i = 0, j; i < m; i++) {
      cin >> p >> c;
      p--;

      s[p] = c;
      j = (p >= n/2) ? n - 1 - p : p;

      if (mark[j] && s[j] != s[n-1-j])
        cnt++;
      else if (!mark[j] && s[j] == s[n-1-j])
        cnt--;

      mark[j] = s[j] == s[n-1-j];

      if (cnt == 0)
        ans++;
    }

    cout << ans << "\n";
  }
  return 0;
}
