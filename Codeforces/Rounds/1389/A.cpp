// Codeforces - LCM Problem - 1389A
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  int64_t l, r;

  cin >> t;
  while (t--) {
    cin >> l >> r;
    if (l*2 <= r) {
      cout << l << " " << l*2 << "\n";
    } else {
      cout << "-1 -1\n";
    }
  }

  return 0;
}
