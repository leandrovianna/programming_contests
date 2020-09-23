// Codeforces - Sage's Birthday (hard version) - 1419D2
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int a[N], b[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);

  fill(b, b+n, -1);

  int k = 0;
  for (int i = 1; i < n; i += 2) {
    b[i] = a[k];
    k++;
  }

  for (int i = 0; i < n; i++) {
    if (b[i] == -1) b[i] = a[k++];
  }

  k = 0;
  for (int i = 1; i < n-1; i += 2) {
    if (b[i-1] > b[i] && b[i] < b[i+1])
      k++;
  }

  cout << k << "\n";
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << "\n";
  return 0;
}
