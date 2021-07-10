// Codeforces - XORwice - 1421A
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, a, b;
  cin >> t;

  while (t--) {
    cin >> a >> b;
    int x = 0;

    for (int i = 0; i <= 30; i++) {
      if ((a & (1 << i)) == (b & (1 << i))) {
        if (a & (1 << i))
          x |= (1 << i);
      }
    }

    cout << (a ^ x) + (b ^ x) << "\n";
  }

  return 0;
}
