// Codeforces Gym - Cakey McCakeFace - 101635A 
#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int a[N], b[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  map<int, int> diff_count;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] > b[j]) continue;

      diff_count[b[j] - a[i]]++;
    }
  }

  auto best = min_element(diff_count.begin(), diff_count.end(),
      [](const auto &a, const auto &b) {
        return a.second > b.second
          || (a.second == b.second && a.first < b.first);
      });

  cout << best->first << "\n";
  return 0;
}
