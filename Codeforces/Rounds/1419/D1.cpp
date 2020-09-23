// Codeforces - Sage's Birthday (easy version) - 1419D1
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
  for (int i = 1; i < n-1; i += 2) {
    b[i] = a[k];
    k++;
  }
  cout << k << "\n";

  for (int i = 0; i < n; i++) {
    if (b[i] == -1) b[i] = a[k++];

    cout << b[i] << " ";
  }
  cout << "\n";
  return 0;
}
