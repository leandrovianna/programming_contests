// Codeforces - I Brook the Code! - 102536K 
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;

pair<int64_t, int64_t> person[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> person[i].second;
  }
  for (int i = 0; i < n; i++) {
    cin >> person[i].first;
  }

  sort(person, person+n);

  for (int i = 0; i < n; i++) {
    cout << person[i].second;
    if (i < n-1)
      cout << " ";
    else
      cout << "\n";
  }
  return 0;
}
