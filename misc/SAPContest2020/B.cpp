#include <bits/stdc++.h>
using namespace std;

const int N = 1001000;
const int inf = 1e9;

void build(int seg[], int idx, int l, int r) {
  if (l == r)
      seg[idx] = 0;
  else {
    int mid = (l + r) >> 1;
    build(seg, 2*idx+1, l, mid);
    build(seg, 2*idx+2, mid+1, r);
    seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
  }
}

void update_seg(int seg[], int idx, int l, int r, int i, int v) {
  if (i < l || i > r)
    return;

  if (l == r) {
    seg[idx] = v;    
  } else {
    int mid = (l + r) >> 1;
    update_seg(seg, 2*idx+1, l, mid, i, v);
    update_seg(seg, 2*idx+2, mid+1, r, i, v);
    seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
  }
}

int query_seg(int seg[], int idx, int l, int r, int i, int j) {
  if (j < l || i > r)
    return inf;

  if (i <= l && r <= j)
    return seg[idx];
  else {
    int mid = (l + r) >> 1;
    return min(
        query_seg(seg, 2*idx+1, l, mid, i, j),
        query_seg(seg, 2*idx+2, mid+1, r, i, j)
        );
  }
}

int n, m;
int64_t skip[N], x, y;

void update(int seg[], int i, int v) {
  update_seg(seg, 0, 0, n+1, i, v);
}

int query(int seg[], int i, int j) {
  return query_seg(seg, 0, 0, n+1, i, j);
}

int seg[2][4*N];


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

  update(seg[0], 0, 0);
  update(seg[1], 0, 0);

  for (int i = 1; i <= n+1; i++) {
    update(seg[0], i, inf);
    update(seg[1], i, inf);
  }

  for (int i = 1; i <= n+1; i++) {
    int j = lower_bound(skip, skip+i, skip[i] - x) - skip;
    int k = lower_bound(skip, skip+i, skip[i] - y) - skip;

    if (j < i) {
      update(seg[0], i, 1 + min(query(seg[0], j, i-1), query(seg[1], j, i-1)));
    }

    if (k < i) {
      update(seg[1], i, 1 + query(seg[0], k, i-1));
    }
  }

  int64_t ans = min(query(seg[0], n+1, n+1), query(seg[1], n+1, n+1));

  cout << (ans >= inf ? -1 : ans) << "\n";
  return 0;
}
