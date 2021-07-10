// Codeforces - Minimum Ties - 1487C
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int r[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;

    if (n == 2) {
      cout << "0\n";
      continue;
    }

    memset(r, 0, sizeof(r));

    for (int c = 1; c <= n/2; c++) {
      cout << "hello " << c << endl;
      for (int i = 1, k; i <= c; i++) {
        cout << "hello " << i << endl;
        for (k = i+c; k <= n; k += c) {
          r[k-c][k] = 1;
          r[k][k-c] = -1;
          cout << k-c << " -> " << k << endl;
        }
        r[k-c][i] = 1;
        r[i][k-c] = -1;
        cout << k-c << " -> " << i << endl;
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = i+1; j <= n; j++) {
        cout << r[i][j] << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
