#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  int64_t ans = 0, x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    ans += x / 3;
  }

  cout << ans * 3 << "\n";
  
  return 0;
}
