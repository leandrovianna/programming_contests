// Kattis - Unique Snowflakes - snowflakes
#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;
int a[N], cnt[N];

bool check(int mid, int n) {
    fill(cnt, cnt+n, 0);
    int repeated = 0; // greater than 1 occ.
    for (int i = 0; i < mid; i++) {
      cnt[a[i]]++;
      if (cnt[a[i]] == 2)
        repeated++;
    }

    for (int i = 0, j; i < n-mid+1; i++) {
      j = i + mid - 1;

      // test for [i, j]
      if (repeated == 0) {
        return true;
      }

      // move sliding window
      cnt[a[i]]--;
      if (cnt[a[i]] == 1)
        repeated--;

      if (j < n-1) {
        cnt[a[j+1]]++;
        if (cnt[a[j+1]] == 2)
          repeated++;
      }
    }

    return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n;
  cin >> t;
  while (t--) {
    map<int, int> idx;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      if (idx.find(x) == idx.end())
        idx[x] = idx.size();

      a[i] = idx[x];
    }

    int lo = 0, hi = n, mid;
    while (lo <= hi) {
      mid = (lo + hi) >> 1;

      if (check(mid, n)) {
        lo = mid+1;
      } else {
        hi = mid-1;
      }
    }

    cout << hi << "\n";
  }
  
  return 0;
}
