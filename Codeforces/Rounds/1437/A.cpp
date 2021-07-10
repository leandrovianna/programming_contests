// Codeforces - Marketing Scheme - 1437A
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, l, r;
  cin >> t;
  while (t--) {
    cin >> l >> r;

    if (r < 2*l || l >= (r+2) / 2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
