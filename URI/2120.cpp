// URI - Tutores - 2120
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int keys[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  set<int> order;
  map<int, int> parent, level;

  int n;
  cin >> n;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    keys[i] = x;

    if (!order.empty()) {
      auto upperit = order.lower_bound(x);
      auto lowerit = prev(upperit);

      if (upperit == order.begin()) {
        // upperit is begin
        // sorted seq: X W ...
        parent[x] = *upperit;
        level[x] = level[*upperit] + 1;
      }
      else if (upperit == order.end()) {
        // upperit is end
        // sorted seq: ... W X
        parent[x] = *lowerit;
        level[x] = level[*lowerit] + 1;
      } else {
        // lowerit and upperit are in the middle

        // sorted seq: ... Z X Y ...
        int z = *lowerit, y = *upperit;

        // upperit (Y) is the parent? (Case 1)
        // Y is in the subtree of Z?
        if (level[y] > level[z]) {
          parent[x] = y;
          level[x] = level[y] + 1;
        } else {
          // lowerit (Z) is the parent?
          // Z is in the subtree of Y?
          parent[x] = z;
          level[x] = level[z] + 1;
        }
      }
    }

    order.insert(x);
  }

  int q;
  cin >> q;
  for (int i = 0, j; i < q; i++) {
    cin >> j;
    cout << parent[keys[j-1]];
    if (i < q-1)
      cout << " ";
  }
  cout << "\n";

  return 0;
}
