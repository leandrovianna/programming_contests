// Codeforces Gym - Husam and the Broken Present 1 - 101343J 
#include <bits/stdc++.h>
using namespace std;

const int N = 15, M = 110;
int a[N][M], len[N];
int dp[N][1 << N];
bool used[N][1 << N];
int cost[N][N];
int n, m;
bool disable[N];

int f(int i, int vis) {
  int &ans = dp[i][vis];

  if (__builtin_popcount(vis) == m)
    return 0;

  if (used[i][vis]) return ans;
  used[i][vis] = true;

  ans = -1e9;
  for (int v = 0; v < n; v++) {
    if (disable[v]) continue;

    if (!(vis & (1 << v))) {
      ans = max(ans, cost[i][v] + f(v, vis | (1 << v)));
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  int size = 0;
  for (int i = 0; i < n; i++) {
    cin >> len[i];
    for (int j = 0; j < len[i]; j++) {
      cin >> a[i][j];
    }

    size += len[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;

      for (int k = min(len[i], len[j]); k >= 1; k--) {
        bool findCost = true;
        for (int l = 0; l < k; l++) {
          if (a[i][len[i]-k+l] != a[j][l]) {
            findCost = false;
            break;
          }
        }

        if (findCost) {
          cost[i][j] = k;
          break;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (disable[i]) continue;

    for (int j = 0; j < n; j++) {
      if (i != j && len[i] < len[j]) {
        for (int k = 0; k < len[j]-len[i]+1; k++) {
          bool inside = true;

          for (int l = 0; l < len[i]; l++) {
            if (a[j][k+l] != a[i][l]) {
              inside = false;
              break;
            }
          }

          if (inside) {
            disable[i] = true;
            break;
          }
        }
      }
    }
  }

  m = n;
  for (int i = 0; i < n; i++) {
    if (disable[i]) {
      m--;
      size -= len[i];
    }
  }

  int best_ans = 0;
  for (int i = 0; i < n; i++) {
    if (disable[i]) continue;

    int x = f(i, 1 << i);
    best_ans = max(best_ans, x);
  }

  cout << size - best_ans << "\n";
  return 0;
}
