// Codeforces Gym - Lucky Chances - 100801L - NEERC Nothern Subregional
#include <bits/stdc++.h>
using namespace std;

//
const int N = 110;
int grid[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ifstream fin("lucky.in");
  ofstream fout("lucky.out");

  int r, c;
  fin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      fin >> grid[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      // up
      ans++;
      for (int k = i-1; k >= 0; k--) {
        if (grid[k][j] >= grid[i][j]) {
          ans--;
          break;
        }
      }

      // down
      ans++;
      for (int k = i+1; k < r; k++) {
        if (grid[k][j] >= grid[i][j]) {
          ans--;
          break;
        }
      }

      // left
      ans++;
      for (int k = j-1; k >= 0; k--) {
        if (grid[i][k] >= grid[i][j]) {
          ans--;
          break;
        }
      }

      // right
      ans++;
      for (int k = j+1; k < c; k++) {
        if (grid[i][k] >= grid[i][j]) {
          ans--;
          break;
        }
      }
    }
  }

  fout << ans << "\n";

  return 0;
}
