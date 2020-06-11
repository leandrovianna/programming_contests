// Codeforces Gym - In the Chairmain's office - 101343G 
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;

  cin >> n >> m;

  if (m % n == 0)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
