// Codeforces - Digit Game - 1419A
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n;
  char ch;
  cin >> t;

  while (t--) {
    cin >> n;

    int cnt[2][2] = {{0, 0}, {0, 0}};

    for (int i = 1, d; i <= n; i++) {
      cin >> ch;
      d = ch - '0';

      cnt[i % 2][d % 2]++;
    }

    bool turn = false;
    for (int i = 0; i < n-1; i++) {
      if (!turn) {
        // Raze play
        if (cnt[1][0] > 0)
          cnt[1][0]--;
        else
          cnt[1][1]--;
      } else {
        // Breach play
        if (cnt[0][1] > 0)
          cnt[0][1]--;
        else
          cnt[0][0]--;
      }

      turn = !turn;
    }

    if (cnt[0][1] > 0 || cnt[1][1] > 0)
      cout << "1\n"; // Raze wins
    else
      cout << "2\n"; // Breach wins
  }
  return 0;
}
