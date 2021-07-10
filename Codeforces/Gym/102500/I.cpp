// Codeforces - Inverted Deck - 102500I
#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;
int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  a[n] = 1e9+10;

  bool found = false;
  pair<int, int> interval = {0, 0};

  int len = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i-1] >= a[i]) {
      len++;
    } else {
      if (len > 1 && a[i-len] != a[i-1]) {
        if (found) {
          cout << "impossible\n";
          return 0;
        }

        found = true;
        interval = {i - len, i-1};
      }

      len = 1;
    }
  }

  if ((interval.first == 0 || a[interval.first-1] <= a[interval.second])
      && (interval.second == n-1 || a[interval.first] <= a[interval.second+1])) {
    cout << interval.first+1 << " " << interval.second+1 << "\n";
  } else {
    cout << "impossible\n";
  }

  return 0;
}
