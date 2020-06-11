// Codeforces Gym - So you think you can count? - 101343B 
#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int n;
int a[N];
int64_t dp[N];
const int64_t mod = 1e9 + 7;
const int D = 10;

int64_t f(int i) {
  if (i == n) return 1;

  int64_t &ans = dp[i];
  if (ans != -1) return ans;

  int rep[D];
  memset(rep, 0, sizeof(rep));

  ans = 0;
  for (int j = 0; j < 10 && i+j < n; j++) {
    rep[a[i+j]]++;
    if (rep[a[i+j]] > 1) break;
    ans = (ans + f(i+j+1)) % mod;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    a[i] = s[i] - '0';
  }

  memset(dp, -1, sizeof(dp));
  cout << f(0) % mod << "\n";
  return 0;
}
