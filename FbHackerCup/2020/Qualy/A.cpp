// Facebook Hacker Cup - Travel Restrictions - A - Qualification
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int adj[N][N];
int dist[N][N];

void bfs(int s, int n) {
  queue<int> q;
  q.push(s);

  for (int u = 0; u < n; u++)
    dist[s][u] = -1;
  dist[s][s] = 0;

  while (!q.empty()) {
    auto v = q.front();
    q.pop();

    for (int u = 0; u < n; u++) {
      if (u != v && adj[v][u] > 0 && dist[s][u] == -1) {
        dist[s][u] = dist[s][v] + 1;
        q.push(u);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  char ch;
  int t, n;
  cin >> t;

  for (int ti = 1; ti <= t; ti++) {
    cin >> n;
    for (int v = 0; v < n; v++)
      for (int u = 0; u < n; u++)
        adj[v][u] = (abs(v - u) <= 1) ? 1 : 0;

    // incomings
    for (int i = 0; i < n; i++) {
     cin >> ch; 
     if (ch == 'N') {
       if (i > 0)
         adj[i-1][i] = 0;
       if (i < n-1)
         adj[i+1][i] = 0;
     }
    }

    // outgoings
    for (int i = 0; i < n; i++) {
     cin >> ch; 
     if (ch == 'N') {
       if (i > 0)
         adj[i][i-1] = 0;
       if (i < n-1)
         adj[i][i+1] = 0;
     }
    }

    for (int v = 0; v < n; v++) {
      bfs(v, n);
    }

    cout << "Case #" << ti << ":\n";
    for (int v = 0; v < n; v++) {
      for (int u = 0; u < n; u++) {
        cout << (dist[v][u] == -1 ? "N" : "Y");
      }
      cout << "\n";
    }
  }
  return 0;
}
