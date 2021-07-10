#include <bits/stdc++.h>
using namespace std;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int N = 100100;
int a[N], cntjob[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int jobs = 0;
  min_heap<pair<int64_t, int>> pq;

  int64_t x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    pq.push({x, a[i]});

    if (cntjob[a[i]] == 0)
      jobs++;
    cntjob[a[i]]++;
  }

  int64_t answer = 0;

  while (jobs < k) {
    auto p = pq.top();
    pq.pop();

    if (cntjob[p.second] > 1) {
      answer += p.first;
      cntjob[p.second]--;
      jobs++;
    }
  }

  cout << answer << "\n";

  return 0;
}
