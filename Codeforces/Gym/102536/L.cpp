// Codeforces Gym - Break the Pattern! - 102536L 
#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int64_t poly[N];
int deg[N];
int64_t ans[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const int mod = 999983;

  int t;
  cin >> t;

  while (t--) {
    int n, k, l;
    cin >> n >> k >> l;

    set<int64_t> roots;
    int64_t y;
    for (int i = 0; i < l; i++) {
      cin >> y;
      roots.insert(y);
    }

    int qtd = 0;

    if (static_cast<int>(roots.size()) <= k) {
      int d = 0;
      memset(poly, 0, sizeof(poly));
      poly[0] = 1;
      for (const auto &x : roots) {
        for (int i = d; i >= 0; i--) {
          poly[i+1] = ((poly[i+1] * (mod - x)) % mod + poly[i]) % mod;
          poly[i+1] = (poly[i+1] + mod) % mod;
        } 
        poly[0] = ((poly[0] * (mod - x)) % mod + mod) % mod;
        d++;
      }

      while (qtd < n) {
        deg[qtd] = d;
        for (int i = 0; i <= d; i++) {
          ans[qtd][i] = poly[i];
          poly[i] = (poly[i] * 2) % mod;
        }
        qtd++;
      }
    }

    cout << qtd << "\n";
    for (int j = 0; j < qtd; j++) {
      cout << deg[j];
      for (int i = deg[j]; i >= 0; i--) {
        cout << " " << ans[j][i];
      }
      cout << "\n";
    }
  }
  return 0;
}
