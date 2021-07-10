// Codeforces - Fair Playoff - 1535A
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, s1, s2, s3, s4;
  cin >> t;
  while (t--) {
    cin >> s1 >> s2 >> s3 >> s4;

    vector<int> v1 = {max(s1, s2), max(s3, s4)};
    vector<int> v2 = {s1, s2, s3, s4};
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    if (v1[0] == v2[2] && v1[1] == v2[3])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
