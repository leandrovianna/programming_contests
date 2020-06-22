// TAP 2018/2 - G4 - Gasolina
#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();
const int64_t LINF = 1000 * 1000 * 1000LL * 1000 * 1000 * 1000LL;
const int V = 2010; // number of vertex

// augment - walk in augmented path and update flow
// adj - adj matrix, p - parent of vertex i, t - sink
int64_t augment(int64_t adj[][V], int p[], int t) {
	int u = t;
	int64_t minimum = LINF;

	// find minimum flow in augmented path
	while (p[u] != -1) {
		minimum = min(adj[p[u]][u], minimum);
		u = p[u];
	}

	// walk in augment path updating flow
	u = t;
	while (p[u] != -1) {
		adj[p[u]][u] -= minimum;
		adj[u][p[u]] += minimum;
		u = p[u];
	}

	return minimum; // return minimum flow in augmented path
}

// s - source, t - sink, n - number of vertex
int64_t edmonds_karp(int64_t adj[][V], const int s, const int t) {

	int64_t mf = 0, // max flow answer
			f = 1;
	int64_t dist[V];
	int p[V];
	int u;

	while (f > 0) {
		f = 0;
		for (int i = 0; i < V; i++)
		    dist[i] = LINF, p[i] = -1;
		dist[s] = 0;

		queue<int> q;
		q.push(s);

		while (!q.empty()) {
			u = q.front();
			q.pop();

			// stop if reach sink t
			if (u == t) break;

			for (int v = 0; v < V; v++) {
				if (adj[u][v] > 0 && dist[v] == LINF) {
					dist[v] = dist[u] + 1;
					q.push(v);
					p[v] = u;
				}
			}
		}

		// verify if bfs stop when reach sink t
		if (u == t) {

			// find minimum flow in augmented path
			f = augment(adj, p, t);

			// update max flow of network
			mf += f;
		}
	}

	return mf;
}

void add_edge(int64_t adj[][V], int v, int u, int64_t cap) {
    adj[v][u] = cap;
    adj[u][v] = 0;
}

const int E = 20100;
int edges[E][3];

int64_t adj[V][V], adj2[V][V];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int p, r, c;
    int s, t;

    cin >> p >> r >> c;

    s = p + r;
    t = p + r + 1;

    int64_t max_flow = 0;
    for (int i = 0, d; i < p; i++) {
        cin >> d;
        max_flow += d;
        add_edge(adj, r+i, t, d);
    }

    for (int i = 0, e; i < r; i++) {
        cin >> e;
        add_edge(adj, s, i, e);
    }

    for (int i = 0, ri, pi, ti; i < c; i++) {
        cin >> pi >> ri >> ti;
        edges[i][0] = r+pi-1;
        edges[i][1] = ri-1; 
        edges[i][2] = ti;
    }

    int lo = 1, hi = 1000 * 1000, mid, ans = -1;

    while (lo <= hi) {
        mid = (lo + hi) / 2;

        // copy source graph
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj2[i][j] = adj[i][j];
            }
        }

        // add edge of time less than or equal mid
        for (int i = 0; i < c; i++) {
            if (edges[i][2] <= mid) {
                add_edge(adj2, edges[i][1], edges[i][0], 1e9);
            }
        }

        // flow in source graph + (edges with time <= mid)
        int64_t flow = edmonds_karp(adj2, s, t);
        if (flow == max_flow) {
            ans = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    cout << ans << "\n";

    return 0;
}
