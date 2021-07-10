// Codeforces - Segment Intersections - 1389D
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
struct interval {
  int l, r;
} a[N], b[N];

int intersec_length(int i) {
  if (a[i].r < b[i].l || b[i].r < a[i].l)
    return 0;

  return min(a[i].r, b[i].r) - max(a[i].l, b[i].l);
}

template<typename T>
using min_heap = priority_queue<T, vector<T>, less<T>>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  int n, k, l, r;
  cin >> t;

  while (t--) {
    cin >> n >> k;

    cin >> l >> r;
    for (int i = 0; i < n; i++) {
      a[i].l = l;
      a[i].r = r;
    }

    cin >> l >> r;
    for (int i = 0; i < n; i++) {
      b[i].l = l;
      b[i].r = r;
    }

    min_heap<pair<int, int>> heap;
    int acc = 0;
    for (int i = 0; i < n; i++) {
      acc += intersec_length(i);

      if (intersec_length(i) == 0) {
        // no intersection
        int cost = 1 + (a[i].r < b[i].l ? b[i].l - a[i].r : a[i].l - b[i].r);
        heap.push({cost, i});
      } else {
        int cost = (a[i].l == b[i].l && a[i].r == b[i].r ? 2 : 1);
        heap.push({cost, i});
      }
    }

    int steps = 0;
    while (acc < k && !heap.empty()) {
      auto p = heap.top();
      heap.pop();

      int i = p.second;

      if (intersec_length(i) == 0) {
        steps += p.first;
        acc++;
        if (a[i].r < b[i].l) {
          b[i].l = a[i].r - 1;
        } else {
          a[i].l = b[i].r - 1;
        }
      }
    }
  }
  return 0;
}
