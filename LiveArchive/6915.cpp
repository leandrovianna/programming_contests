// UVa - Leveling Ground - 6915
#include <bits/stdc++.h>
using namespace std;

const int N = 1000100, K = 22;
int lg[N+1];
int st[N][K+1];
int64_t h[N];
void pre(int n) {
  lg[1] = 0;
  for (int i = 2; i <= N; i++) {
    lg[i] = lg[i/2] + 1;
  }

  for (int i = 0; i < n; i++) {
    st[i][0] = h[i];
  }

  for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= n; i++)
      st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
}

int64_t query(int l, int r) {
  int j = lg[r - l + 1];
  return min(st[l][j], st[r - (1 << j) + 1][j]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n, m;
  string inp;
  char ch;

  cout << fixed << setprecision(1);

  cin >> t;
  for (int ti = 1; ti <= t; ti++) {
    cin >> n >> m;
    cin >> inp;

    int64_t curr = 0;
    for (int i = 0; i < n; i++) {
      ch = inp[i];

      if (ch == '/') {
        h[i] = curr++;
      } else if (ch == '\\') {
        h[i] = --curr;
      } else {
        h[i] = curr;
      }
    }

    pre(n);

    int64_t s = 0;
    int cDesc = 0, cAsc = 0;
    for (int i = 0; i < m; i++) {
      if (inp[i] == '/') cAsc++;
      else if (inp[i] == '\\') cDesc++;

      s += h[i];
    }

    int64_t alpha = query(0, m-1);
    double ans = cDesc * 0.5 + cAsc * 0.5 + s - m * alpha;
    double x;

    for (int i = 0, j = m; j < n; i++, j++) {
      s -= h[i];
      if (inp[i] == '/') cAsc--;
      else if (inp[i] == '\\') cDesc--;

      s += h[j];
      if (inp[j] == '/') cAsc++;
      else if (inp[j] == '\\') cDesc++;

      alpha = query(i+1, j);
      x = cDesc * 0.5 + cAsc * 0.5 + s - m * alpha;
      ans = min(ans, x);
    }

    cout << "Case #" << ti << ": " << ans << "\n";
  }

  return 0;
}
