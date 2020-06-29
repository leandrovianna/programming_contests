// URI - Parkour - 3114 
#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;
pair<int, int> building[N], process_queue[N];
pair<int, int> g[N];
int64_t npath[N];

inline int64_t mod(int64_t x, int64_t m) {
  if (x >= m)
    return x - m;
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // mod value
  const int64_t m = 1e9 + 7;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> building[i].second >> building[i].first;
  }

  sort(building, building+n);

  stack<pair<int, int>> aux;
  // left neighbor
  for (int i = 0; i < n; i++) {
    while (!aux.empty() && aux.top().first <= building[i].second) {
      aux.pop();
    }

    g[i].first = aux.empty() ? -1 : aux.top().second;

    aux.push({building[i].second, i});
  }

  // clear aux stack
  while (!aux.empty()) aux.pop();

  // right neighbor
  for (int i = n-1; i >= 0; i--) {
    while (!aux.empty() && aux.top().first <= building[i].second) {
      aux.pop();
    }

    g[i].second = aux.empty() ? -1 : aux.top().second;

    aux.push({building[i].second, i});
  }

  for (int i = 0; i < n; i++) {
    process_queue[i] = {building[i].second, i};
  }
  sort(process_queue, process_queue+n);
  reverse(process_queue, process_queue+n);

  int64_t ans = 0;

  for (int j = 0; j < n; j++) {
    int i = process_queue[j].second;

    npath[i] = 0;
    if (g[i] == make_pair(-1, -1))
      npath[i] = 1;

    if (g[i].first != -1)
      npath[i] = mod(npath[i] + npath[g[i].first], m);

    if (g[i].second != -1)
      npath[i] = mod(npath[i] + npath[g[i].second], m);

    ans = mod(ans + npath[i], m);
  }

  cout << ans << "\n";

  return 0;
}
