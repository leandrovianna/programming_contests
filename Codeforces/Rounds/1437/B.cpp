// Codeforces - Reverse Binary Strings - 1437B
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n;
  char ch;
  cin >> t;

  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> ch;
      a[i] = ch - '0';
    }

    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == a[i])
        ans2++; // 1010
      else
        ans1++; // 0101
    }

    cout << min(ans1, ans2) / 2 << "\n";

  }

  return 0;
}
