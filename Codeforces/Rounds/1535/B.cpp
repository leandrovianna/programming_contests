// Codeforces - Array Reordering - 1535B
#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
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

    sort(a, a+n, [](const int a, const int b) {
          if (a % 2 == b % 2) {
            return a < b;
          } else {
            return a % 2 == 0;
          }
        });

    int answer = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        int g = __gcd(a[i], 2 * a[j]);
        if (g > 1) {
          answer++;
        }
      }
    }

    cout << answer << "\n";
  }
  return 0;
}
