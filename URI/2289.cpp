// URI - Distância de Hamming - 2289
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  uint64_t a, b;

  while (cin >> a >> b, a || b) {
    int ans = __builtin_popcountll(a ^ b);
    cout << ans << "\n";
  }
  return 0;
}
