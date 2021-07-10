// Codeforces - Yet Another Crosses Problem - 1194B
#include <bits/stdc++.h>
using namespace std;

const int N = 50010;
string g[N];
int cntl[N], cntc[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int q, n, m;
  cin >> q;

  while (q--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> g[i];
    }

    for (int i = 0; i < n; i++) {
      cntl[i] = 0;
      for (int j = 0; j < m; j++) {
        if (g[i][j] == '*')
          cntl[i]++;
      }
    }

    for (int j = 0; j < m; j++) {
      cntc[j] = 0;
      for (int i = 0; i < n; i++) {
        if (g[i][j] == '*')
          cntc[j]++;
      }
    }

    int ans = n + m - 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int v = (m - cntl[i]) + (n - cntc[j]);
        if (g[i][j] == '.')
          v--;
        ans = min(ans, v);
      }
    }

    cout << ans << "\n";
  }
  return 0;
}
