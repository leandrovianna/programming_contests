// Codeforces - Unstable String - 1535C
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  string s;

  cin >> t;
  while (t--) {
    cin >> s;

    const int n = s.size();

    int64_t answer = 0, len = 0;

    int bgn = 0;
    while (bgn < n && s[bgn] == '?') {
      bgn++;
      len++;
    }

    if (bgn < n) {
      len++;
    }

    for (int i = bgn+1; i < n; i++) {
      if (s[i] != '?') {
        if (s[i] == s[i-1]) {
          answer += (len * (len+1)) / 2;
          len = 0;
        }
        len++;
      } else {
        int64_t c = 0;
        while (i < n && s[i] == '?') {
          i++;
          c++;
        }

        if (i == n || (s[i-c-1] == s[i] && c % 2 != 0)
            || (s[i-c-1] != s[i] && c % 2 == 0)) {
          len += c;
          if (i < n)
            len++;
        } else {
          answer += ((len+c) * (len+c+1)) / 2;
          answer -= (c * (c+1)) / 2;
          len = c+1;
        }
      }
    }

    answer += (len * (len+1)) / 2;

    cout << answer << "\n";
  }
  return 0;
}
