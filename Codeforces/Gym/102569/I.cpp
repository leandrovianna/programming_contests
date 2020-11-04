// Codeforces Gym - Sorting Colored Array - 102569I
#include <bits/stdc++.h>
using namespace std;

const int N = 200100, inf = 1e9+10;
int last[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < N; i++) last[i] = -inf;

  bool asc = true;
  for (int i = 0, x, c; i < n; i++) {
    cin >> x >> c;

    if (last[c] > x) {
      asc = false;
    }

    last[c] = x;
  }

  cout << (asc ? "YES\n" : "NO\n");
  return 0;
}
