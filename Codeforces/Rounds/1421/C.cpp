// Codeforces - Palindromifier - 1421C
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  cout << "3\n"
    << "R 2\n"
    << "L " << n << "\n"
    << "L " << n-1 << "\n";
  return 0;
}
