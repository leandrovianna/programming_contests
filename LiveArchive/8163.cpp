// Live Archive - Hidden Hierarchy - 8163
#include <bits/stdc++.h>
using namespace std;

struct Node {
  bool isDir;
  string name;
  int64_t size;
};

const int N = 200100;
Node nodes[N];
vector<int> g[N];

int64_t compute_size(int v, int p) {
  int64_t &size = nodes[v].size;

  for (const auto &u :  g[v]) {
    if (u == p) continue;

    size += compute_size(u, v);
  }

  return size;
}

void print_hierarchy(int v, int p, int64_t t) {
  auto &node = nodes[v];
  bool isEmpty = true;
  bool shouldExpand = false;

  for (const auto &u : g[v]) {
    if (u == p) continue;

    if (nodes[u].isDir) {
      isEmpty = false;

      if (nodes[u].size >= t) {
        shouldExpand = true;
      }
    }
  }

  string mark = "";
  if (!isEmpty) {
    mark = shouldExpand ? "- " : "+ ";
  }
  cout << mark << node.name << " " << node.size << "\n";

  if (shouldExpand) {
    for (const auto &u : g[v]) {
      if (u == p) continue;

      if (nodes[u].isDir) {
        print_hierarchy(u, v, t);
      }
    }
  }
}

bool cmp(int i, int j) {
  return nodes[i].name < nodes[j].name;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  string s, name;

  int64_t f, t;

  while (cin >> n) {
    map<string, int> idx;
    int k = 0;

    // add root
    idx["/"] = k;
    g[k].clear();
    nodes[k++] = {true, "/", 0}; // root

    for (int i = 0; i < n; i++) {
      cin >> s >> f;

      int node = 0;
      name = "/";
      for (int j = 1, m = s.size(); j < m; j++) {
        name += s[j];

        if (s[j] == '/') {
          if (idx.find(name) == idx.end()) {
            // add directory
            idx[name] = k;
            g[k].clear();
            nodes[k++] = {true, name, 0};
            g[node].push_back(idx[name]);
          }

          node = idx[name];
        }
      }

      // add file
      idx[name] = k;
      g[k].clear();
      nodes[k++] = {false, name, f};
      g[node].push_back(idx[name]);
    }

    cin >> t;

    compute_size(0, -1);
    for (int v = 0; v < k; v++) {
      sort(g[v].begin(), g[v].end(), cmp);
    }
    print_hierarchy(0, -1, t);
  }
  
  return 0;
}
