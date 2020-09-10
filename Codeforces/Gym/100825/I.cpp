// Codeforces - What's on the Grille - 100825I
#include <bits/stdc++.h>
using namespace std;

pair<int, int> rotate(pair<int, int> p, int n) {
  return {p.second, n - 1 - p.first};
}

const int N = 14;
bool mark[N][N];
char grid[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> pos;
  char ch;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> ch;
      if (ch == '.')
        pos.push_back({i, j});
    }
  }

  string encrypted;
  cin >> encrypted;

  for (int q = 0, i, j, k = 0; q < 4; q++) {
    for (auto &p : pos) {
      tie(i, j) = p;

      if (k < n*n) {
        grid[i][j] = encrypted[k++];
        mark[i][j] = true;
      } else {
        cout << "invalid grille\n";
        return 0;
      }

      p = rotate(p, n);
    }

    sort(pos.begin(), pos.end());
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!mark[i][j]) {
        cout << "invalid grille\n";
        return 0;
      }
    }
  }

  string plain = "";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      plain += grid[i][j];
    }
  }
  cout << plain << "\n";

  return 0;
}
