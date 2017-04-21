#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define N 150010

typedef vector<int> vii;

vii g[N];
int comp[N];

bool dfs(int v) {
	int n;

	for (int i = 0; i < g[v].size(); i++) {
		n = g[v][i];
		if (comp[n] == -1) {
			comp[n] = comp[v];
			dfs(n);
		}
	}

	return true;
}

int main() {
	int n, m, a, b, label, value;

	cin >> n >> m;

	memset(comp, -1, sizeof(comp));

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	label = 0;

	for (int i = 0; i < n; i++) {
		if (comp[i] == -1) {
			comp[i] = label++;
			dfs(i);
		}
	}

	long long verts[N], edges[N];
	memset(verts, 0, sizeof(verts));
	memset(edges, 0, sizeof(edges));

	for (int i = 0; i < n; i++) {
		verts[comp[i]]++;		
		// add degree of vertex
		edges[comp[i]] += g[i].size();
	}

	for (int i = 0; i < n; i++) {
		// divide by 2 for correct result
		if (edges[i] > 0)
			edges[i] /= 2;
	}

	// remember of theorem 2 * number of edges = sum of degrees

	for (int i = 0; i < n; i++) {
		// each component need be a complete subgraph
		if (edges[i] != verts[i] * (verts[i]-1) / 2)
			return cout << "NO" << endl, 0;
	}

	cout << "YES" << endl;
	return 0;
}
