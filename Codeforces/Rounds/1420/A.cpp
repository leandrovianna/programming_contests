// Codeforces - Cubes Sorting - 1420A
#include <bits/stdc++.h>
using namespace std;

const int N = 500100;
int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    bool desc = true;
    for (int i = 1; i < n; i++) {
      if (a[i-1] <= a[i]) {
        desc = false;
        break;
      }
    }

    cout << (desc ? "NO" : "YES") << "\n";
  }
  return 0;
}
