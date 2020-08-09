// URI - Surf Aquático - 2560
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, b;

  while (cin >> n >> b) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    multiset<int> values;
    int sum = 0;
    for (int i = 0; i < b; i++) {
      sum += a[i];
      values.insert(a[i]);
    }

    int64_t ans = 0;
    for (int i = 0, j = b-1; j < n; i++, j++) {
      ans += sum - *values.begin() - *prev(values.end());

      values.erase(values.find(a[i]));
      sum -= a[i];

      values.insert(a[j+1]);
      sum += a[j+1];
    }

    cout << ans << "\n";
  }
  return 0;
}
