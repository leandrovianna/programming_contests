// Codeforces - Putting Bricks in the Wall - 1421B
#include <bits/stdc++.h>
using namespace std;

const int N = 210;
char grid[N][N];

const int I[] = {+1, +0, -1, +0};
const int J[] = {+0, +1, +0, -1};
bool vis[N][N];
bool test(int n) {
  for (int type = 0; type <= 1; type++) {
    grid[n-1][n-1] = '0' + type;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        vis[i][j] = false;
      }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
      auto p = q.front();
      q.pop();

      if (p.first == n-1 && p.second == n-1)
        return true;

      if (vis[p.first][p.second])
        continue;
      vis[p.first][p.second] = true;

      for (int k = 0, di, dj; k < 4; k++) {
        di = p.first + I[k];
        dj = p.second + J[k];

        if (0 <= di && di < n && 0 <= dj && dj < n && grid[di][dj] - '0' == type) {
          q.push({di, dj});
        }
      }
    }
  }

  return false;
}

void flip(pair<int, int> p) {
  auto i = p.first, j = p.second;
  grid[i][j] = (grid[i][j] == '0') ? '1' : '0';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> grid[i][j];
      }
    }

    if (!test(n)) {
      cout << "0\n";
      continue;
    }

    bool found = false;
    pair<int, int> positions[] = {{0, 1}, {1, 0}, {n-1, n-2}, {n-2, n-1}};

    for (int i = 0; !found && i < 4; i++) {
      auto p1 = positions[i];

      flip(p1);
      if (!test(n)) {
        found = true;
        cout << "1\n" << p1.first+1 << " " << p1.second+1 << "\n";
        break;
      }
      flip(p1);

      for (int j = 0; !found && j < 4; j++) {
        auto p2 = positions[j];

        flip(p2);
        if (!test(n)) {
          found = true;
          cout << "1\n" << p2.first+1 << " " << p2.second+1 << "\n";
          break;
        }
        flip(p2);

        flip(p1);
        flip(p2);
        if (!test(n)) {
          found = true;
          cout << "2\n"
            << p1.first+1 << " " << p1.second+1 << "\n"
            << p2.first+1 << " " << p2.second+1 << "\n";
        }
        flip(p1);
        flip(p2);
      }
    }
  }
  return 0;
}
