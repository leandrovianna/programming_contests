// Codeforces Gym - Painting the Fence - 102348E
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int a[N], ans[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;  

  priority_queue<pair<int, int>> pq;
  vector<pair<int, int>> remaining;

  for (int i = 0, q; i < m; i++) {
    cin >> q;
    remaining.push_back({q, i+1});
  }

  int ans_size = 0;
  
  while (remaining.size() > 0) {
    for (const auto &p : remaining) {
      pq.push(p);
    }
    remaining.clear();

    while (!pq.empty()) {
      auto best = pq.top();
      pq.pop();

      if (best.first == 1) {
        ans[ans_size++] = best.second;
        continue;
      }

      for (int i = 0; i < k && best.first > 1; i++) {
        ans[ans_size++] = best.second;
        best.first--;
      }

      if (best.first > 0)
        remaining.push_back(best);
    }
  }

  bool answerOk = true;
  int countContiguos = 1;
  for (int i = 1; i < n; i++) {
    if (ans[i] == ans[i-1])
      countContiguos++;
    else
      countContiguos = 1;

    if (countContiguos > k) {
      answerOk = false;
      break;
    }
  }

  if (answerOk) {
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  } else {
    cout << "-1\n";
  }

  return 0;
}
