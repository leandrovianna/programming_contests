// Live Archive - Immortal Porpoises - 7361
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2;
struct matrix {
  int64_t m[MAXN][MAXN];
};

matrix mult(matrix a, matrix b, int64_t mod) {
  matrix ans;
  for (int i = 0; i < MAXN; i++) {
    for (int j = 0; j < MAXN; j++) {
      ans.m[i][j] = 0;
      for (int k = 0; k < MAXN; k++) {
        ans.m[i][j] += (a.m[i][k] * b.m[k][j]) % mod;
      }
      ans.m[i][j] %= mod;
    }
  }
  return ans;
}

matrix power(matrix base, int64_t exp, int64_t mod) {
  matrix ans;
  for (int i = 0; i < MAXN; i++) {
    for (int j = 0; j < MAXN; j++) {
      ans.m[i][j] = i == j ? 1 : 0;
    }
  }

  while (exp) {
    if (exp & 1)
      ans = mult(ans, base, mod);

    base = mult(base, base, mod);
    exp >>= 1;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int mod = 1e9;
  const matrix base = {
    {
      {1, 1},
      {1, 0}
    }
  };

  int p, k;
  int64_t n;

  cin >> p;
  while (p--) {
    cin >> k >> n;

    auto ans = power(base, n, mod);

    cout << k << " " << ans.m[0][1] << "\n";
  }

  return 0;
}
