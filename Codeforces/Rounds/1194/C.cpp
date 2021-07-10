// Codeforces - From S to T - 1194C
#include <bits/stdc++.h>
using namespace std;

const int E = 300;
int markp[E];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int q;
  cin >> q;

  string s, t, p;

  while (q--) {
    cin >> s >> t >> p;

    memset(markp, 0, sizeof(markp));
    for (const auto &ch : p) {
      markp[ch - '0']++;
    }

    bool possible = true;

    int si = 0, n = s.size();
    for (const auto &ch : t) {
      if (si < n && ch == s[si]) {
        si++;
      } else if (markp[ch - '0'] > 0) {
        markp[ch - '0']--;
      } else {
        possible = false;
        break;
      }
    }

    cout << (possible && si == n ? "YES\n" : "NO\n");
  }
  return 0;
}
