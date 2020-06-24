// Codeforces Gym - Shattered Cake - 101635F
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t total_width, area = 0, w, l;

  cin >> total_width;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> w >> l;
    area += w * l;
  }

  int64_t total_length = area / total_width;
  cout << total_length << "\n";
  return 0;
}
