// URI - Letras - 1714
#include <bits/stdc++.h>
using namespace std;

const int M = 10;
bool enabled[2*M];

const int N = 101, inf = 1e9;
char g[N][N];
int dist[N][N];
bool vis[N][N];

const int I[] = {-1, +0, +1, +0};
const int J[] = {+0, -1, +0, +1};

int index(char c) {
  return isupper(c) ? c - 'A' + M : c - 'a';
}

int bfs(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = inf;
      vis[i][j] = false;
    }
  }

  queue<pair<int, int>> q;
  if (enabled[index(g[0][0])]) {
    q.push({0, 0});
    dist[0][0] = 1;
  }

  int i, j;
  while (!q.empty()) {
    tie(i, j) = q.front();
    q.pop();

    if (vis[i][j]) continue;
    vis[i][j] = true;

    for (int k = 0, di, dj; k < 4; k++) {
      di = I[k] + i;
      dj = J[k] + j;
      if (0 <= di && di < n && 0 <= dj && dj < n
          && enabled[index(g[di][dj])]) {
        if (!vis[di][dj]) {
          dist[di][dj] = dist[i][j] + 1;
          q.push({di, dj});
        }
      }
    }
  }

  return dist[n-1][n-1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
  }

  int ans = inf;
  for (int mask = 0; mask < (1 << M); mask++) {
    for (int i = 0; i < M; i++) {
      // enable lower case
      enabled[i] = mask & (1 << i);
      // disable upper case
      enabled[i + M] = !enabled[i];
    }
    int d = bfs(n);
    ans = min(ans, d);
  }

  cout << (ans == inf ? -1 : ans) << "\n";
  
  return 0;
}
