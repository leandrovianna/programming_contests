// Facebook Hacker Cup - Alchemy - B - Qualification
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n; 
  char ch;

  cin >> t;

  for (int ti = 1; ti <= t; ti++) {
    cin >> n;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
      cin >> ch;
      if (ch == 'A') c1++;
      else c2++;
    }

    if (c1 > c2) swap(c1, c2);

    cout << "Case #" << ti << ": " << (c1 + 1 == c2 ? "Y" : "N") << "\n";
  }
  return 0;
}
