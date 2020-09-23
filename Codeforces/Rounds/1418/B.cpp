// Codeforces - Negative Prefixes - 1418B
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N];
bool locked[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<int> numbers;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      locked[i] = x == 1;

      if (!locked[i])
        numbers.push_back(a[i]);
    }

    sort(numbers.begin(), numbers.end());
    reverse(numbers.begin(), numbers.end());

    for (int i = 0, j = 0; i < n; i++) {
      if (!locked[i])
        a[i] = numbers[j++];
    }

    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
