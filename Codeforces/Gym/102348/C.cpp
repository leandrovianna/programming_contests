// Codeforces - Marbles - 102348C
#include <bits/stdc++.h>
using namespace std;

const int M = 20, N = 400100;
int64_t dp[M][1 << M];
bool used[M][1 << M];
int cnt[M], a[N];
vector<int> pos[M];
const int64_t inf = 1e18;

inline int len(int mask) {
  return __builtin_popcount(mask);
}

int64_t solve(int i, int vis) {
  int64_t &ans = dp[i][vis];
  if (used[i][vis]) return ans;
  used[i][vis] = true;

  if (vis & (1 << i)) return inf;

  // visited all
  if (len(vis) == M-1) return 0;

  int init = 0;
  for (int j = 0; j < M; j++) {
    if (vis & (1 << j))
      init += cnt[j];
  }

  int64_t inc = 0;
  for (int j = 0; j < cnt[i]; j++) {
    int k = (init+j) - pos[i][j];
    inc += abs(k);
  }

  ans = inf;
  for (int j = 0; j < M; j++) {
    // if (j == i) continue;
    if ((vis & (1 << j)) == false)
      ans = min(ans, inc + solve(j, (1 << i) | vis));
  }
  
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    cnt[a[i]]++;
    pos[a[i]].push_back(i);
  }

  int64_t ans = inf;
  for (int i = 0; i < M; i++) {
    int64_t x = solve(i, 0);
    ans = min(ans, x);
  }

  cout << ans << "\n";
  
  return 0;
}
