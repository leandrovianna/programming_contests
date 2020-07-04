// Min cost max flow
// UVA 10594 - Data Flow

#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();
const int64_t LINF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000LL;
const int N = 150; // number of vertex
const int M = 4*5002; // number of edges

struct edge {
  // v - from vertex
  // u - to vertex
  int v, u, next;
  int64_t cap, cost;
} edges[M];

int first[N], edgenum = 0;

// initialize algorithm structs
void init(int sz = N) {
  for (int i = 0; i < sz; i++) {
    first[i] = -1;
  }
  edgenum = 0;
}

// add a directed edge v -> u and residual edge v <- u
void add_edge(int v, int u, int64_t cap, int64_t cost) {
  edge &e = edges[edgenum];
  e.v = v;
  e.u = u;
  e.cap = cap;
  e.cost = cost;
  e.next = first[v];
  first[v] = edgenum;
  edgenum++;

  // residual edge
  edge &e2 = edges[edgenum];
  e2.v = u;
  e2.u = v;
  e2.cap = 0;
  e2.cost = -cost;
  e2.next = first[u];
  first[u] = edgenum;
  edgenum++;
}

int64_t dist[N];
int in_queue[N], p[N];

// augment - walk in augmented path and update flow
// u - sink or final of path
int64_t augment(int u) {
  int64_t minimum = LINF;

  // find minimum flow in augmented path
  for (int k = p[u]; k != -1; k = p[edges[k].v]) {
    minimum = min(edges[k].cap, minimum);
  }

  // walk in augment path updating flow
  for (int k = p[u]; k != -1; k = p[edges[k].v]) {
    // forward edge
    edges[k].cap -= minimum;
    // residual edge
    edges[k^1].cap += minimum;
  }

  return minimum; // return minimum flow in augmented path
}

// s - source, t - sink, n - number of vertex [0, ..., n-1]
pair<int64_t, int64_t> mcmf(const int s, const int t, const int n) {
  int64_t mf = 0, // max flow answer
          min_cost = 0, // min cost answer
          f = 1; // current min cost

  while (f > 0) {
    f = 0;
    for (int i = 0; i < n; i++) {
      dist[i] = LINF;
      p[i] = -1;
      in_queue[i] = 0;
    }

    dist[s] = 0;

    queue<int> q;
    q.push(s);
    in_queue[s] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      in_queue[u] = 0;

      for (int k = first[u], v; k != -1; k = edges[k].next) {
        v = edges[k].u;
        if (edges[k].cap > 0 && dist[v] > dist[u] + edges[k].cost) {
          dist[v] = dist[u] + edges[k].cost;
          p[v] = k;
          if (in_queue[v] == 0) {
            q.push(v);
            in_queue[v] = 1;
          }
        }
      }
    }

    // verify if bfs stop when reach sink t
    if (dist[t] != LINF) {
      // find minimum flow in augmented path
      f = augment(t);

      // update max flow of network
      min_cost += f * dist[t];
      mf += f;
    }
  }

  return {mf, min_cost};
}


int main() {
  int a[M], b[M];
  int64_t c[M];
  int n, m;
  int64_t d, k;
  int source, sink;

  while (cin >> n >> m) {
    init(n+10);

    for (int i = 0; i < m; i++) {
      cin >> a[i] >> b[i] >> c[i];
    }

    cin >> d >> k;

    for (int i = 0; i < m; i++) {
      add_edge(a[i], b[i], k, c[i]);
      add_edge(b[i], a[i], k, c[i]);
    }

    source = 0;
    sink = n;

    add_edge(source, 1, d, 0);

    auto p = mcmf(source, sink, n+1);

    if (p.first != d) {
      printf("Impossible.\n");
    } else {
      printf("%jd\n", p.second);
    }
  }

  return 0;
}
