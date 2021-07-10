// Codeforces Gym - UEFA Champions League - 101778I
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int gh1, ga2, ga1, gh2;
  int t1, t2;

  int t;
  cin >> t;
  while (t--) {
    cin >> gh1 >> ga2 >> ga1 >> gh2;
    t1 = gh1 + ga1;
    t2 = gh2 + ga2;

    if (t1 == t2) {
      if (ga1 > ga2)
        cout << "1\n";
      else if (ga1 < ga2)
        cout << "2\n";
      else
        cout << "-1\n";
    } else if (t1 > t2) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }
  return 0;
}
