#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int a[N], b[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }

    sort(a, a+n);
    sort(b, b+m);

    int answer = 0;

    for (int i = 0; i < n; i++) {
      auto it = lower_bound(b, b+m, a[i]);
      if (it == b+m) {
        answer = max(answer, n - i);
      } else {
        auto it2 = lower_bound(a, a+n, *it);
        answer = max(answer, (int)(it2 - a) - i);
      }
    }

    if (answer == 0) {
      cout << "Impossible\n";
    } else {
      cout << answer << "\n";
    }
  }

  return 0;
}
