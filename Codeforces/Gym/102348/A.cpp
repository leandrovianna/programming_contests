// Codeforces Gym - Yellow Cards - 102348A - Southern and Volga Qualifier
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int a[2], k[2], n;
  cin >> a[0] >> a[1];
  cin >> k[0] >> k[1];
  cin >> n;

  int nearThrowOut = a[0] * (k[0]-1) + a[1] * (k[1]-1);
  cout << max(0, n - nearThrowOut) << " ";

  int maxThrowOut = 0;
  if (k[0] > k[1]) {
    swap(a[0], a[1]);
    swap(k[0], k[1]);
  }
  for (int i = 0; i <= 1; i++) {
    while (a[i] > 0 && n >= k[i]) {
      n -= k[i];
      a[i]--;
      maxThrowOut++;
    }
  }

  cout << maxThrowOut << "\n";
  
  return 0;
}
