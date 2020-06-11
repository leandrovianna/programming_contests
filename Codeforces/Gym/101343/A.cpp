// Codeforces - On the way to Lucky Plaza - 101343A
#include <bits/stdc++.h>
using namespace std;

int64_t exp(int64_t base, int64_t e, int64_t mod) {
  assert(e >= 0);

  int64_t ans = 1;
  while (e) {
    if (e & 1)
      ans = (ans * base) % mod;
    base = (base * base) % mod;
    e >>= 1;
  }

  return ans;
}

int64_t inv(int64_t x, int64_t mod) {
  return exp(x, mod-2, mod);
}

int64_t comb(int n, int k, int mod) {
  if (n < k) return 0;

  int64_t num = 1, den = 1;

  for (int i = 2; i <= n; i++) {
    num = (num * i) % mod;
  }

  for (int i = 2; i <= k; i++) {
    den = (den * i) % mod;
  }

  for (int i = 2; i <= n-k; i++) {
    den = (den * i) % mod;
  }

  return (num * inv(den, mod)) % mod;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int64_t m, n, k;
  cin >> m >> n >> k; 

  int64_t dp, p;
  cin >> dp;
  cin.get(); // skip point
  cin >> p;
  p = dp * 1000 + p;

  if (n < k) {
    cout << "0\n";
    return 0;
  }

  const int mod = 1e9 + 7;

  const int64_t thousandInv = inv(1000, mod);
  const int64_t p_inv = ((1000 - p) * thousandInv) % mod;
  p = (p * thousandInv) % mod;

  const int64_t n1 = exp(p, k, mod);
  const int64_t n2 = exp(p_inv, n-k , mod);
  const int64_t n3 = comb(n-1, k-1, mod);

  int64_t ans = (n1 * n2) % mod;
  ans = (ans * n3) % mod;

  cout << ans << "\n";
  return 0;
}
