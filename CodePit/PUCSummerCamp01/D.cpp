//Puc Summer Camp 2018
//URI - Colônia de Formigas - D
#include <bits/stdc++.h>
using namespace std;

const int N = 100100, L = 20;
vector<pair<int, int64_t>> g[N];
int64_t dist[N];
int parent[N][L], lvl[N];

void dfs(int v, int p) {
	parent[v][0] = p;
	lvl[v] = lvl[p] + 1;

	int64_t w;
	for (int j = 0, u; j < (int)g[v].size(); j++) {
		u = g[v][j].first;
		w = g[v][j].second;

		if (u == p) continue;

		dist[u] = dist[v] + w;
		dfs(u, v);
	}
}

void pre_lca(int n) {
	for (int i = 1; i < L; i++) {
		for (int v = 0; v < n; v++) {
			parent[v][i] = parent[parent[v][i-1]][i-1];
		}
	}
}

int lca(int a, int b) {
	if (lvl[a] < lvl[b]) {
		swap(a, b);
	}

	int d = lvl[a] - lvl[b];

	for (int i = L-1; i >= 0; i--) {
		if (d & (1 << i)) {
			a = parent[a][i];
		}
	}

	if (a == b) return a;

	for (int i = L-1; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	return parent[a][0];
}

int main() {
	ios::sync_with_stdio(false);
	int n, a, b;

	while (cin >> n, n) {
		memset(g, 0, sizeof(g));

		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			g[i].push_back(make_pair(a, b));
			g[a].push_back(make_pair(i, b));
		}

		dist[0] = 0;
		lvl[0] = 0;
		dfs(0, 0);

		pre_lca(n);

		int q;
		cin >> q;
		for (int i = 0; i < q; i++) {
			cin >> a >> b;
			cout << dist[a] + dist[b] - 2 * dist[lca(a,b)];
			if (i < q-1)
				cout << " ";
			else
				cout << endl;
		}
	}

	return 0;
}
