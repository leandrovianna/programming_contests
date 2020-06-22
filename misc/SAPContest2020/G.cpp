#include <bits/stdc++.h>
using namespace std;

int64_t ceil(int64_t a, int64_t b) {
  return a / b + (a % b != 0 ? 1 : 0);
}

int64_t calc_price(int64_t n, int64_t m, int x, int y) {
  int64_t len1 = ceil(n, x+1);
  int64_t len2 = ceil(m, y+1);

  return max(len1, len2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int64_t n, m;
  int k;
  
  cin >> n >> m >> k;

  int64_t best_price = 1e18;

  for (int i = 1, j; i <= k; i++) {
    j = k / i;

    best_price = min({best_price, calc_price(n, m, i-1, j-1), 
        calc_price(n, m, j-1, i-1)});
  }

  cout << best_price << "\n";
  
  return 0;
}
