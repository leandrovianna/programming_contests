// Codeforces Gym - Printer - 102348L - Southern and Volga Qualifier
#include <bits/stdc++.h>
using namespace std;

const int F = 2, N = 1010;
bool tab[F][N];
int maxf[F];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  string s[F];
  cin >> s[1] >> s[0];

  for (int f = 0; f <= 1; f++) {
    for (int i = 0; i < n; i++) {
      tab[f][i] = s[f][i] == '1';
      if (tab[f][i])
        maxf[f] = i+1;
    }
  }

  int ans = INT_MAX, f_best = 0, p_best = 0;

  for (int p = 0; p < n; p++) {
    for (int f = 0; f <= 1; f++) {
      int x = 0;
      for (int i = 0; i < n; i++) {
        if (tab[f][i])
          x = max(x, abs((i+1) - (p+1)));
      }

      if (maxf[1 - f] > 0)
        x = max(x, maxf[1 - f] + k + (p+1));

      if (x < ans) {
        ans = x;
        f_best = f + 1;
        p_best = p + 1;
      }
    }
  }

  cout << ans << "\n"
    << f_best << " " << p_best << "\n";

  return 0;
}
