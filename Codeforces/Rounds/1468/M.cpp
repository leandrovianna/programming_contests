#include <bits/stdc++.h>
using namespace std;

const int S = 200100;
const int N = 500100;
vector<int> g[N];
int lvl[N];
bool vis[N];

int getleft(int x) {
  return x;
}

int getright(int x) {
  return S + x;
}

bool iselem(int x) {
  return x < S;
}

pair<int, int> answer;

int dfs(int v, int p) {
  vis[v] = true;
  lvl[v] = (p == -1 ? 0 : lvl[p]) + 1;

  for (const auto &u : g[v]) {
    if (!vis[u]) {
      int r = dfs(u, v);
      if (r > 0) {
        if (!iselem(u)) {
          if (answer.first == -1)
            answer.first = u - S + 1;
          else if (answer.second == -1)
            answer.second = u - S + 1;
        }
        return r-1;
      }
    } else if (lvl[v] - lvl[u] == 3) {
      if (answer.first == -1 && !iselem(u)) {
        answer.first = u - S + 1;
      }
      return 3;
    }
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;

    // clear set vertices
    for (int j = 0; j < n; j++) {
      g[getright(j)].clear();
      vis[getright(j)] = false;
    }

    map<int, int> idx;

    for (int i = 0, k; i < n; i++) {
      cin >> k;
      for (int j = 0, x; j < k; j++) {
        cin >> x;
        if (idx.find(x) == idx.end()) {
          idx[x] = idx.size();
          // clear element vertices
          g[getleft(idx[x])].clear();
          vis[getleft(idx[x])] = false;
        }

        int a = idx[x];
        g[getleft(a)].push_back(getright(i));
        g[getright(i)].push_back(getleft(a));
      }
    }

    answer = {-1, -1};
    dfs(0, -1);

    if (answer.first != -1) {
      cout << answer.first << " " << answer.second << "\n";
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}
