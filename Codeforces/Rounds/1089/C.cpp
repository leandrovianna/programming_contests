#include <bits/stdc++.h>
using namespace std;

const int N = 510, inf = 1e9;
int64_t dist[N][N];

void floyd_warshall(int n) {
    for (int v = 0; v < n; v++) {
        for (int u = 0; u < n; u++) {
            for (int q = 0; q < n; q++) {
                dist[u][q] = min(dist[u][q], dist[u][v] + dist[v][q]);
            }
        }
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = inf;
    }
  }

  for (int i = 0, ki, v, u; i < m; i++) {
    cin >> ki;
    cin >> v;
    for (int j = 0; j < ki-1; j++) {
      cin >> u;
      u--;
      v--;
      dist[u][v] = 1;
      dist[v][u] = 1;
      v = u;
    }
  }

  floyd_warshall(n);

  vector<int> verts;
  for (int v = 0; v < n; v++)
    verts.push_back(v);

  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  
  string answer;
  
  for (int tries = 0; tries < 10; tries++) {
    int j = uniform_int_distribution<int>(0, verts.size()-1)(rng);
    int u = verts[j];
    for (const auto &v : verts) {
      cout << v << " ";
    }
    cout << endl;

    cout << u << endl;
    cin >> answer;

    if (answer == "FOUND")
      break;

    // answer is GO
    cin >> answer; // get the number
    int w = stoi(answer);

    vector<int> verts2;
    for (const auto &v : verts) {
      if (dist[v][w] < dist[v][u]) {
        verts2.push_back(v);
      }
    }

    verts = verts2;
  }

  return 0;
}
