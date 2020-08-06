// Live Archive - K.Bro Sorting - 7068
#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;
int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n;

  cin >> t;
  for (int ti = 1; ti <= t; ti++) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int ans = 0, tmp = N;
    for (int i = n-1; i >= 0; i--) {
      if (a[i] > tmp)
        ans++;

      tmp = min(tmp, a[i]);
    }

    cout << "Case #" << ti << ": " << ans << "\n";
  }
  return 0;
}
