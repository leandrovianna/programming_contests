// Codeforces Gym - Mason's Mark - 102465I 
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
const int I[] = {-1, -1, -1, +0, +0, +1, +1, +1};
const int J[] = {-1, +0, +1, -1, +1, -1, +0, +1};
const int OUTER = 0, INNER = 1;

int w, h;
inline bool on(int i, int j) {
  return 0 <= i && i < h && 0 <= j && j < w;
}

bool grid[N][N];
int comp[N][N];

void dfs_remove(int i, int j) {
  grid[i][j] = false;

  for (int k = 0; k < 8; k++) {
    int di = i + I[k];
    int dj = j + J[k];

    if (on(di, dj) && grid[di][dj]) 
      dfs_remove(di, dj);
  }
}

pair<pair<int, int>, pair<int, int>> pos[N*N];
bool vis[N][N];
void dfs(int i, int j, int compid) {
  pos[compid].first.first = min(pos[compid].first.first, i);
  pos[compid].first.second = min(pos[compid].first.second, j);

  pos[compid].second.first = max(pos[compid].second.first, i);
  pos[compid].second.second = max(pos[compid].second.second, j);

  comp[i][j] = compid;
  vis[i][j] = true;

  for (int k = 0; k < 8; k++) {
    int di = i + I[k];
    int dj = j + J[k];

    if (on(di, dj) && !vis[di][dj] && grid[di][dj] == grid[i][j])
      dfs(di, dj, compid);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> w >> h;

  char ch;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> ch;
      grid[i][j] = (ch == '#');
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j]) {
        bool isNoise = true;

        for (int k = 0; k < 8; k++) {
          int di = i + I[k];
          int dj = j + J[k];

          if (on(di, dj) && grid[di][dj]) {
            isNoise = false;
            break;
          }
        }

        if (isNoise)
          grid[i][j] = false;
      }
    }
  }

  // remove border
  dfs_remove(0, 0);

  dfs(0, 0, OUTER);

  int compid = 2;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (!vis[i][j]) {
        if (grid[i][j]) {
          pos[compid] = {{N, N}, {-1, -1}};
          dfs(i, j, compid++);
        } else
          dfs(i, j, INNER);
      }
    }
  }

  int cA = 0, cB = 0, cC = 0;
  for (int c = 2; c < compid; c++) {
    bool haveOuter = false, haveInner = false;
    for (int i = pos[c].first.first; i <= pos[c].second.first; i++) {
      for (int j = pos[c].first.second; j <= pos[c].second.second; j++) {
        haveInner |= comp[i][j] == INNER;
        haveOuter |= comp[i][j] == OUTER;
      }
    }

    if (haveInner) {
      if (haveOuter)
        cA++;
      else
        cB++;
    } else if (haveOuter) {
      cC++;
    }
  }

  cout << cA << " " << cB << " " << cC << "\n";

  return 0;
}
