// Live Archive - Irrigation Lines - 6811
#include <bits/stdc++.h>
using namespace std;

const int K = 100;
const int N = 2*K+10;
vector<int> g[N];
int match[N], lmatch[N];
bool visited[N];

int augment(int v) {
  if (visited[v]) return 0;
  visited[v] = true;

  for (const auto &u : g[v]) {
    if (match[u] == -1) {
      match[u] = v;
      lmatch[v] = u;
      return 1;
    }
  }

  for (const auto &u : g[v]) {
    if (augment(match[u])) {
      match[u] = v;
      lmatch[v] = u;
      return 1;
    }
  }

  return 0;
}

int matching(int left_sz) {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  for (int i = 0; i < N; i++) {
    shuffle(g[i].begin(), g[i].end(), rng);
  }

  memset(match, -1, sizeof(match));
  memset(lmatch, -1, sizeof(lmatch));

  int mcmb = 0, m;
  bool keep = true;

  while (keep) {
    keep = false;

    for (int i = 0; i < left_sz; i++) {
      visited[i] = false;
    }
    for (int i = 0; i < left_sz; i++) {
      if (lmatch[i] == -1) {
        m = augment(i);
        mcmb += m;
        if (m > 0)
          keep = true;
      }
    }
  }

  return mcmb;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, m, n;
  char ch;

  cin >> t;

  for (int ti = 1; ti <= t; ti++) {
    cin >> m >> n;
    for (int v = 0; v < n+m; v++)
      g[v].clear();

    auto left = [](int i) {
      return i;
    };
    auto right= [m](int i) {
      return m + i;
    };

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> ch;

        if (ch == '1') {
          g[left(i)].push_back(right(j));
          g[right(j)].push_back(left(i));
        }
      }
    }

    cout << "Case #" << ti << ": " << matching(m) << "\n";
  }
  return 0;
}
