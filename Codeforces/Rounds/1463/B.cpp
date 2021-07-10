// Codeforces - Find the Array - 1463B
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int64_t a[N], b[N];

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

    b[0] = a[0];
    for (int i = 1; i < n; i++) {
      int64_t c = a[i] / b[i-1];

      if (abs(a[i] - b[i-1] * c) <= abs(a[i] - b[i-1] * (c+1))) {
        b[i] = b[i-1]
      }
    }

    for (int i = 0; i < n; i++) {
      cout << b[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
