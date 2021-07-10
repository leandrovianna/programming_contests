#include <bits/stdc++.h>
using namespace std;

const int E = 300;
bool mark[E];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s, t;
  getline(cin, s);
  getline(cin, t);

  string answer = "";

  for (int i = 0, j = 0, len = s.size(), len2 = t.size(); i < len; i++, j++) {

    int cnt = 1;
    while (i < len-1 && s[i] == s[i+1]) {
      cnt++;
      i++;
    }

    int cnt2 = 1;
    while (j < len2-1 && t[j] == t[j+1]) {
      cnt2++;
      j++;
    }

    //cout << s[i] << " " << t[j] << endl;
    //cout << cnt << " " << cnt2 << endl;

    if (!mark[(int) s[i]] && cnt2 == 2*cnt)
      answer += s[i];

    mark[(int) s[i]] = true;
  }

  cout << answer << "\n";
  return 0;
}
