#include <bits/stdc++.h>
using namespace std;

const int N = 1001000;
const int inf = 1e9;
int seg[4*N][2];

void build(int idx, int l, int r, int s) {
  if (l == r)
      seg[idx][s] = 0;
  else {
    int mid = (l + r) >> 1;
    build(2*idx+1, l, mid, s);
    build(2*idx+2, mid+1, r, s);
    seg[idx][s] = min(seg[2*idx+1][s], seg[2*idx+2][s]);
  }
}

void update(int idx, int l, int r, int i, int v, int s) {
  if (i < l || i > r)
    return;

  if (l == r) {
    seg[idx][s] = v;    
  } else {
    int mid = (l + r) >> 1;
    update(2*idx+1, l, mid, i, v, s);
    update(2*idx+2, mid+1, r, i, v, s);
    seg[idx][s] = min(seg[2*idx+1][s], seg[2*idx+2][s]);
  }
}

int query(int idx, int l, int r, int i, int j, int s) {
  if (j < l || i > r)
    return inf;

  if (i <= l && r <= j)
    return seg[idx][s];
  else {
    int mid = (l + r) >> 1;
    return min(
        query(2*idx+1, l, mid, i, j, s),
        query(2*idx+2, mid+1, r, i, j, s)
        );
  }
}

int n, m;
int64_t skip[N], x, y;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  skip[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> skip[i];
  }
  skip[n+1] = m;

  cin >> x >> y;

  build(0, 0, n+1, 0);
  build(0, 0, n+1, 1);

  update(0, 0, n+1, 0, 0, 0);
  update(0, 0, n+1, 0, 0, 1);

  for (int i = 1; i <= n+1; i++) {
    update(0, 0, n+1, i, inf, 0);
    update(0, 0, n+1, i, inf, 1);
  }

  for (int i = 1; i <= n+1; i++) {
    int j = lower_bound(skip, skip+i, skip[i] - x) - skip;
    int k = lower_bound(skip, skip+i, skip[i] - y) - skip;

    if (j < i) {
      update(0, 0, n+1, i, 
          1 + min(query(0, 0, n+1, j, i-1, 0), 
            query(0, 0, n+1, j, i-1, 1)), 0);
    }

    if (k < i) {
      update(0, 0, n+1, i, 1 + query(0, 0, n+1, k, i-1, 0), 1);
    }
  }

  int64_t ans = min(query(0, 0, n+1, n+1, n+1, 0), 
      query(0, 0, n+1, n+1, n+1, 1));

  cout << (ans >= inf ? -1 : ans) << "\n";
  return 0;
}
