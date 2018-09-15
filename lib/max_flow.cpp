#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();
const int64_t LINF = 1000 * 1000 * 1000LL * 1000 * 1000 * 1000LL;
const int V = 110; // number of vertex

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
int64_t edmonds_karp(int64_t adj[][V], const int s, const int t, const int n) {

	int64_t mf = 0, // max flow answer
			f = 1;
	int64_t dist[V];
	int p[V];
	int u;

	while (f > 0) {
		f = 0;
		for (int i = 0; i < n; i++)
		    dist[i] = LINF, p[i] = -1;
		dist[s] = 0;

		queue<int> q;
		q.push(s);

		while (!q.empty()) {
			u = q.front();
			q.pop();

			// stop if reach sink t
			if (u == t) break;

			for (int v = 0; v < n; v++) {
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

int main() {
	ios::sync_with_stdio(false);
		
	int n, m, k;
	int a, b, source, sink;
	int64_t adj[V][V], c;

	k = 1;
	while (cin >> n, n) {
		// cleaning adj matrix
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				adj[i][j] = 0;

		cin >> source >> sink >> m;
		source--;
		sink--;

		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			a--;
			b--;
			adj[a][b] += c;
			adj[b][a] += c;
		}

		c = edmonds_karp(adj, source, sink, n);
		cout << "Network " << k << "\nThe bandwidth is " << c << ".\n\n";
		k++;
	}

	return 0;
}
