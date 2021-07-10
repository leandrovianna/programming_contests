#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, c1, c2, c3, a1, a2, a3, a4, a5;

  cin >> t;
  while (t--) {
    cin >> c1 >> c2 >> c3;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;

    bool answer = false;

    if (a1 <= c1 && a2 <= c2 && a3 <= c3) {
      c1 -= a1;
      c2 -= a2;
      c3 -= a3;

      if (a4 <= c1 + c3) {
        c3 -= max(0, a4 - c1);

        if (a5 <= c2 + c3) {
          answer = true;
        }
      }
    }

    cout << (answer ? "YES" : "NO") << "\n";
  }

  return 0;
}
