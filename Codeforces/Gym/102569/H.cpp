// Codeforces Gym - Tree Painting - 102569H
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int deg[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0, u, v; i < n-1; i++) {
    cin >> u >> v;
    deg[u]++;
    deg[v]++;
  }

  int leafs = 0;
  for (int v = 1; v <= n; v++) {
    if (deg[v] == 1) {
      leafs++;
    }
  }

  cout << (leafs+1) / 2 << "\n";
  return 0;
}
