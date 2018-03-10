//CodePit - Minha Camiseta Me Serve - E
//URI - '' - 1362
#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();
const int64_t LLINF = numeric_limits<int64_t>::max();
const int V = 110; // number of vertex

// augment - walk in augmented path and update flow
// adj - adj matrix, p - parent of vertex i, t - sink
int64_t augment(int64_t adj[][V], int p[], int t) {
	int u = t;
	int64_t minimum = LLINF;

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
	int dist[V];
	int p[V];
	int u;

	while (f > 0) {
		f = 0;
		for (int i = 0; i < n; i++) dist[i] = INF, p[i] = -1;
		dist[s] = 0;

		queue<int> q;
		q.push(s);

		while (!q.empty()) {
			u = q.front();
			q.pop();

			// stop if reach sink t
			if (u == t) break;

			for (int v = 0; v < n; v++) {
				if (adj[u][v] > 0 && dist[v] == INF) {
					dist[v] = dist[u] + 1, q.push(v), p[v] = u;
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

int get(string s) {
	if (s == "XXL")
		return 50;
	if (s == "XL")
		return 51;
	if (s == "L")
		return 52;
	if (s == "M")
		return 53;
	if (s == "S")
		return 54;
	if (s == "XS")
		return 55;

	return 0;
}

int main() {
	ios::sync_with_stdio(false);

	int t, n, m;
	string c1, c2;

	int64_t adj[V][V];

	cin >> t;
	while (t--) {
		memset(adj, 0, sizeof(adj));

		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			cin >> c1 >> c2;

			int j1 = get(c1);
			int j2 = get(c2);

			adj[0][i] = 1;
			adj[i][0] = 0;

			adj[i][j1] = 1;
			adj[j1][i] = 0;
			adj[i][j2] = 1;
			adj[j2][i] = 0;
		}

		adj[get("XXL")][60] = n/6;
		adj[get("XL")][60] = n/6;
		adj[get("L")][60] = n/6;
		adj[get("M")][60] = n/6;
		adj[get("S")][60] = n/6;
		adj[get("XS")][60] = n/6;

		adj[60][get("XXL")] = 0;
		adj[60][get("XL")] = 0;
		adj[60][get("L")] = 0;
		adj[60][get("M")] = 0;
		adj[60][get("S")] = 0;
		adj[60][get("XS")] = 0;

		cout << (edmonds_karp(adj, 0, 60, V) == m ? "YES" : "NO") << endl;
	}

	return 0;
}
