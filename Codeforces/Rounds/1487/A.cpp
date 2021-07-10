// Codeforces - Arena - 1487A
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
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

    sort(a, a+n);
    int cnt = 1;
    for (int i = 1; i < n; i++) {
      if (a[i-1] == a[i]) {
        cnt++;
      } else {
        break;
      }
    }

    cout << n - cnt << "\n";
  }
  return 0;
}
