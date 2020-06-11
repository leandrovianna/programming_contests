// Codeforces Gym - Abdalrahman Ali Bugs - 101343C 
#include <bits/stdc++.h>
using namespace std;

const int E = 27, N = 100100;
int64_t f[E];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s = "";
  cin >> s;

  for (const auto &ch : s) {
    f[ch - 'a']++;
  }

  int64_t ans = 1e18, ans_x;
  for (int64_t x = 2; x < N; x++) {
    int64_t value = 0;
    for (int e = 0; e < E; e++) {
      value += (f[e] % x) * f[e];
    }

    if (value < ans) { 
      ans = value;
      ans_x = x;
    }
  }

  cout << ans_x << "\n";
  return 0;
}
