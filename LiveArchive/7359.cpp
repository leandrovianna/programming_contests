// Live Archive - Sum Kind Of Problem - 7359
#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int64_t s1[N], s2[N], s3[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  s1[0] = 0;
  for (int i = 1; i < N; i++) {
    s1[i] = s1[i-1] + i;

    s2[i] = s2[i-1] + 2*i - 1;
    s3[i] = s3[i-1] + 2*i;
  }

  int p, k, n;

  cin >> p;
  while (p--) {
    cin >> k >> n;

    cout << k << " "
      << s1[n] << " "
      << s2[n] << " "
      << s3[n] << "\n";
  }

  return 0;
}
