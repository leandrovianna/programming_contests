// Codeforces - Odd Palindrome - 101615A
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  bool answer = true;

  for (int i = 0; i < n-1; i++) {
    if (s[i] == s[i+1]) answer = false;
  }

  cout << (answer ? "Odd.\n" : "Or not.\n");
  return 0;
}
