// Codeforces Gym - Katastrophic sort - 102700K
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;

  string w1 = "", w2 = "";
  string p1 = "", p2 = "";

  for (const auto &ch : s1) {
    if (isalpha(ch))
      w1 += ch;
    else {
      p1 += ch;
    }
  }

  for (const auto &ch : s2) {
    if (isalpha(ch))
      w2 += ch;
    else
      p2 += ch;
  }

  if (w1 < w2) {
    cout << "<\n";
  } else if (w1 > w2) {
    cout << ">\n";
  } else {
    if (p1.size() < p2.size())
      p1 = string(p2.size() - p1.size(), '0') + p1;
    else if (p1.size() > p2.size())
      p2 = string(p1.size() - p2.size(), '0') + p2;

    if (p1 < p2)
      cout << "<\n";
    else if (p1 > p2)
      cout << ">\n";
    else
      cout << "=\n";
  }

  return 0;
}
