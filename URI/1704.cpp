// URI - Arrumando as Tarefas - 1704
#include <bits/stdc++.h>
using namespace std;

// getchar_unlocked


const int N = 1010;

struct Task {
  int v, t;
} task[N];

int dp[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int inf = 1e9;

  int n, h;
  while (cin >> n >> h) {
    int total = 0;
    for (int i = 0; i < n; i++) {
      cin >> task[i].v >> task[i].t;
      total += task[i].v;
    }
    sort(task, task+n, [](const auto &t1, const auto &t2) {
        return t1.t < t2.t || (t1.t == t2.t && t1.v < t2.v);
      });

    dp[0] = 0;
    for (int t = 1; t <= h; t++) dp[t] = -inf;
    for (int i = 0; i < n; i++) {
      for (int t = task[i].t; t >= 1; t--) {
        dp[t] = max(dp[t], task[i].v + dp[t-1]);
      }
    }

    int ans = 0;
    for (int t = 0; t <= h; t++)
      ans = max(ans, dp[t]);

    cout << total - ans << "\n";
  }
  return 0;
}
