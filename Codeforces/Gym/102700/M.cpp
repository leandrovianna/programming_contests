// Codeforces Gym - Magic spells - 102700M
#include <bits/stdc++.h>
using namespace std;

const int E = 30;
vector<int> pos[E];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;

  int i = 0;
  for (const auto &ch : s) {
    pos[ch - 'a'].push_back(i);
    i++;
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;

    int j = -1, ans = 0;
    for (const auto &ch : s) {
      auto it = lower_bound(pos[ch - 'a'].begin(), pos[ch - 'a'].end(), j+1);

      if (it == pos[ch - 'a'].end())
        break;
      else {
        j = *it;
        ans++;
      }
    }

    if (ans == 0)
      cout << "IMPOSSIBLE\n";
    else
      cout << s.substr(0, ans) << "\n";
  }

  return 0;
}
