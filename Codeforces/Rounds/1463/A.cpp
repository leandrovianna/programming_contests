// Codeforces - Dungeon - 1463
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, a, b, c;
  cin >> t;

  while (t--) {
    cin >> a >> b >> c;

    int s = a + b + c;
    int d = s / 9;
    if (s % 9 == 0 && a >= d && b >= d && c >= d) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
