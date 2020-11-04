// Codeforces Gym - Notifications - 102569M
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  int64_t current_time = 1;
  for (int i = 0, t, d; i < n; i++) {
    cin >> t >> d;

    if (current_time < t)
      current_time = t;

    current_time += d;
  }

  cout << current_time << "\n";
  return 0;
}
