// Codeforces Gym - Give Me This Pizza - 101343H 
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int a[N];
const int M = 55;
int pos[M];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  memset(pos, -1, sizeof(pos));
  vector<int> answers;

  for (int i = n-1; i >= 0; i--) {
    pos[a[i]] = i;
    int ans_i = n, ans = -1;
    
    for (int v = a[i] + 1; v < M; v++) {
      if (pos[v] != -1 && ans_i > pos[v]) {
        ans_i = pos[v];
        ans = v;
      }
    }

    answers.push_back(ans);
  }
  
  for (auto it = answers.rbegin(); it != answers.rend(); it++) {
    cout << *it << " ";
  }
  cout << "\n";
  return 0;
}
