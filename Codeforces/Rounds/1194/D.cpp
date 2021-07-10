// Codeforces - 1-2-K Game - 1194D
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  int n, k;

  cin >> t;
  while (t--) {
    cin >> n >> k;

    bool win;
    if (k % 3 != 0)
      win = n % 3 != 0;
    else
      win = n != 0 && (n % 3 != 0 || n % k == 0);

    if (win)
      cout << "Alice\n";
    else
      cout << "Bob\n";
  }
  return 0;
}
