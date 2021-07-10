#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
string answer[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, l, k;
  cin >> n >> l >> k;

  string letters;
  cin >> letters;

  sort(letters.begin(), letters.end());
  int idx = 0;

  for (int i = 0; i < n; i++) {
    answer[i] = "";
  }

  for (int j = 0, bgn = 0; j < l; j++) {
    for (int i = bgn; i < k; i++) {
      answer[i] += letters[idx];
      idx++;
    }

    for (int i = bgn; i < k-1; i++) {
      if (answer[i][j] < answer[i+1][j]) {
        bgn = i+1;
      }
    }

    if (k == 1 || answer[k-1][j] > answer[k-2][j]) {
      while ((int) answer[k-1].size() < l) {
        answer[k-1] += letters[idx];
        idx++;
      }
      break;
    }
  }

  for (int i = 0; i < n; i++) {
    while ((int) answer[i].size() < l) {
      answer[i] += letters[idx];
      idx++;
    }
  }

  string kth = answer[k-1];

  sort(answer, answer+n);

  assert(kth == answer[k-1]);

  for (int i = 0; i < n; i++) {
    cout << answer[i] << "\n";
  }

  return 0;
}
