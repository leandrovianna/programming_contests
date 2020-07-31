// Live Archive - Spokes Wheel - 6809
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int B = 32;
  int t;
  uint32_t x, y;
  string s1, s2, tmp;

  cin >> t;
  for (int ti = 1; ti <= t; ti++) {
    cin >> hex >> x;
    cin >> hex >> y;

    s1 = bitset<B>(x).to_string();
    s2 = bitset<B>(y).to_string();

    int bestLeft = B, bestRight = B;

    tmp = s1;
    for (int r = 0; r < B; r++) {
      for (int j = 0; j < B; j++) {
        s1[(j+r)%B] = tmp[j];
      }

      if (s1 == s2) {
        bestRight = min(bestRight, r);
      }

      for (int j = 0; j < B; j++) {
        s1[(j-r+B)%B] = tmp[j];
      }

      if (s1 == s2) {
        bestLeft = min(bestLeft, r);
      }
    }

    cout << "Case #" << ti << ": ";
    if (bestLeft == B && bestRight == B)
      cout << "Not possible\n";
    else if (bestLeft == bestRight)
      cout << bestLeft << " Any\n";
    else if (bestLeft < bestRight)
      cout << bestLeft << " Left\n";
    else
      cout << bestRight << " Right\n";
  }
  
  return 0;
}
