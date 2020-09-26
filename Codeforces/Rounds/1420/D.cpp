// Codeforces - Rescue Nibel! - 1420D
#include <bits/stdc++.h>
using namespace std;

const int N = 300100;
int64_t fat[N], ifat[N];

int64_t exp(int64_t base, int64_t exp, int64_t mod) {
  int64_t ans = 1;
  while (exp) {
    if (exp & 1) {
      ans = (ans * base) % mod;
    }

    base = (base * base) % mod;
    exp >>= 1;
  }
  return ans;
}

int64_t inv(int64_t x, int64_t m) {
  return exp(x, m-2, m);
}

int64_t comb(int64_t n, int64_t k, int64_t mod) {
  return (((fat[n] * ifat[n-k]) % mod) * ifat[k]) % mod;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int mod = 998244353;
  fat[0] = 1;
  ifat[0] = 1;
  for (int i = 1; i < N; i++) {
    fat[i] = (fat[i-1] * i) % mod;
    ifat[i] = inv(fat[i], mod);
  }

  int n, k;
  cin >> n >> k;

  map<int, int> in, out;
  vector<int> times;

  for (int i = 0, l, r; i < n; i++) {
    cin >> l >> r;
    in[l]++;
    out[r]++;
    times.push_back(l);
    times.push_back(r);
  }
  sort(times.begin(), times.end());
  times.erase(unique(times.begin(), times.end()), times.end());

  int cnt = 0, y;
  int64_t ans = 0;
  for (const auto &x : times) {
    y = in[x];
    cnt += y;

    if (y > 0 && cnt-1 >= k-1) {
      for (int i = 0; cnt-1-i >= k-1 && i < y; i++) {
        int64_t tmp = comb(cnt-1-i, k-1, mod);
        ans = (ans + tmp) % mod;
      }
    }

    cnt -= out[x];
  }

  cout << ans << "\n";

  return 0;
}
