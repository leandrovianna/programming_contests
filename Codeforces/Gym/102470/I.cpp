// Codeforces Gym - Happy Telephones - SWERC 2009
#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
struct Call {
  int src, dest;
  int start, dur;
} calls[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;

  while (cin >> n >> m, n && m) {
    for (int i = 0; i < n; i++) {
      cin >> calls[i].src >> calls[i].dest 
        >> calls[i].start >> calls[i].dur;
    }

    for (int j = 0, st, dur; j < m; j++) {
      cin >> st >> dur;
      
      int ans = 0;
      for (int i = 0; i < n; i++) {
        if (max(st, calls[i].start) < min(st + dur, calls[i].start + calls[i].dur))
          ans++;
      }

      cout << ans << "\n";
    }
  }
  return 0;
}
