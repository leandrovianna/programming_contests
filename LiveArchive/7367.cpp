// Live Archive - RATS - 7367
#include <bits/stdc++.h>
using namespace std;

string rats(string num) {
  int m = num.size();
  string res = "";
  int carry = 0;
  for (int i = 0, j = m-1; i < m; i++, j--) {
    int d1 = num[i] - '0', d2 = num[j] - '0';
    int r = (d1 + d2 + carry);
    res += (char) ('0' + r % 10);
    carry = r / 10;
  }
  if (carry != 0)
    res += (char) ('0' + carry);

  sort(res.begin(), res.end());
  res.erase(remove(res.begin(), res.end(), '0'), res.end());
  return res;
}

bool is_creeper(string num) {
  if (num.size() < 8)
    return false;

  if (num.substr(0, 4) == "1233" && num.substr(num.size() - 5, 5) == "34444")
    return true;
  if (num.substr(0, 4) == "5566" && num.substr(num.size() - 5, 5) == "67777")
    return true;

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int p, k, m;
  string num;

  cin >> p;
  while (p--) {
    cin >> k >> m;
    cin >> num;

    set<string> nums;
    for (int i = 1; i <= m; i++) {
      // cout << i << ": " << num << "\n";

      if (nums.find(num) != nums.end()) {
        // repeated
        cout << k << " R " << i << "\n";
        break;
      }

      if (is_creeper(num)) {
        // creeper
        cout << k << " C " << i << "\n";
        break;
      }

      if (i == m) {
        // print last term
        cout << k << " " << num << "\n";
        break;
      }

      nums.insert(num);
      num = rats(num);
    }
  }

  return 0;
}
