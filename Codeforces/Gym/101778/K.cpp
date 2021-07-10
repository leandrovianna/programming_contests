// Codeforces Gym - Conan and Scoreboard - 101778K
#include <bits/stdc++.h>
using namespace std;

const int K = 10010;
struct {
  int x, y, z, t;
} sub[K];

const int N = 33;
int first_award[N];
int attempts[N][N];
int solved[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n, m, k;
  int x, y, z, mins, secs;
  cin >> t;

  char ch;

  while (t--) {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
      first_award[i] = -1;

      for (int j = 0; j < m; j++) {
        attempts[i][j] = 0;
        solved[i][j] = 0;
      }
    }

    for (int i = 0; i < k; i++) {
      cin >> x >> y >> z;
      cin >> mins >> ch >> secs;

      sub[i].x = x-1;
      sub[i].y = y-1;
      sub[i].z = z;
      sub[i].t = mins * 60 + secs;
    }

    sort(sub, sub+k, [](const auto &a, const auto &b) {
          return a.t < b.t;
      });

    int extreme_award = -1, steadfast_award = -1;

    for (int i = 0; i < k; i++) {
      if (sub[i].z == 1 && first_award[sub[i].x] == -1) {
        first_award[sub[i].x] = sub[i].y+1;
      }

      if (sub[i].z == 1 && extreme_award == -1) {
        extreme_award = sub[i].y+1;
      }

      if (sub[i].z == 1) {
        steadfast_award = sub[i].y+1;
      }

      if (solved[sub[i].x][sub[i].y] == 0)
        attempts[sub[i].x][sub[i].y]++;
      solved[sub[i].x][sub[i].y] = max(solved[sub[i].x][sub[i].y], sub[i].z);
    }

    int solid_count = 0, solid_award = -1;
    for (int j = 0; j < m; j++) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (solved[i][j] == 1 && attempts[i][j] == 1)
          cnt++;
      }

      if (cnt > solid_count) {
        solid_count = cnt;
        solid_award = j+1;
      }
    }

    int rentless_count = 0, rentless_award = -1;
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        if (solved[i][j] == 1) {
          if (attempts[i][j] > rentless_count) {
            rentless_count = attempts[i][j];
            rentless_award = j+1;
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      cout << first_award[i] << " ";
    }
    cout << "\n";
    cout << extreme_award << " "
      << steadfast_award << " "
      << solid_award << " "
      << rentless_award << "\n";
  }
  return 0;
}
