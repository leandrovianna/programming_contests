// Codeforces Gym - Ingredients - 101635E
#include <bits/stdc++.h>
using namespace std;

const int M = 10010;
vector<tuple<int, int, int>> recipes[M];
pair<int, int> dishs[M];
int64_t dp[M];

vector<int> g[M];
bool vis[M];
vector<int> ans;

void dfs(int v) {
  vis[v] = true;  
  for (const auto &u : g[v]) {
    if (!vis[u]) {
      dfs(u);
    }
  }

  ans.push_back(v);
}

void topological_sort(int n) {
  memset(vis, false, sizeof(vis));
  for (int v = 0; v < n; v++) {
    if (!vis[v]) {
      dfs(v);
    }
  }

  reverse(ans.begin(), ans.end());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int b, n;
  cin >> b >> n;

  map<string, int> idx;

  string recipe_name, base_dish, ingre;
  for (int i = 0, cost, prestige; i < n; i++) {
    cin >> recipe_name >> base_dish >> ingre
      >> cost >> prestige;

    if (idx.find(recipe_name) == idx.end()) {
      idx[recipe_name] = idx.size();
    }

    if (idx.find(base_dish) == idx.end()) {
      idx[base_dish] = idx.size();
    }
    
    int recipe = idx[recipe_name];
    int dish = idx[base_dish];
    recipes[recipe].push_back({dish, cost, prestige});

    g[dish].push_back(recipe);
  }

  const int inf = 1e9;
  const int m = idx.size();

  for (int v = 0; v < m; v++) {
    if (recipes[v].empty()) {
      dishs[v] = {0, 0};
    } else {
      dishs[v] = {inf, 0};
    }
  }

  topological_sort(m);
  for (const auto &v : ans) {
    int base, c, p;
    for (const auto &t : recipes[v]) {
      tie(base, c, p) = t;
      auto tmp = make_pair(dishs[base].first + c, dishs[base].second + p);

      if (tmp.first < dishs[v].first) {
        dishs[v] = tmp;
      } else if (tmp.first == dishs[v].first && tmp.second > dishs[v].second) {
        dishs[v] = tmp;
      }
    }
  }

  dp[0] = 0;
  for (int c = 1; c <= b; c++) {
    dp[c] = -1e18;
  }

  for (int i = 0; i < m; i++) {
    for (int c = b; c >= 0; c--) {
      if (c + dishs[i].first <= b) {
        dp[c+dishs[i].first] = max(dp[c+dishs[i].first], dishs[i].second + dp[c]);
      }
    }
  }

  int64_t maxp = 0;
  int bestcost = 0;
  for (int c = 0; c <= b; c++) {
    if (maxp < dp[c]) {
      maxp = dp[c];
      bestcost = c;
    }
  }

  cout << maxp << "\n" << bestcost << "\n";
  return 0;
}
