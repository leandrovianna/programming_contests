#include <bits/stdc++.h>
using namespace std;

const int N = 30;
bool visited[N];
vector<int> g[N];

int dfs(int v) {
	visited[v] = true;
	int mask_component = 1 << v;
	
	for (const auto &u : g[v]) {
		if (!visited[u]) {
			mask_component |= dfs(u);
		}
	}
	
	return mask_component;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t, n, m;
	char v, u;
	
	cin >> t;
	
	for (int ti = 1; ti <= t; ti++) {
		cin >> n >> m;
		for (int v = 0; v < n; v++) {
			visited[v] = false;
			g[v].clear();
		}
		
		for (int i = 0; i < m; i++) {
			cin >> v >> u;
			g[v - 'a'].push_back(u - 'a');
			g[u - 'a'].push_back(v - 'a');
		}
		
		cout << "Case #" << ti << ":\n";
		int qtd = 0;
		for (int v = 0; v < n; v++) {
			if (!visited[v]) {
				qtd++;
				int mask_component = dfs(v);
				
				for (int u = 0; u < n; u++) {
					if (mask_component & (1 << u)) {
						cout << ((char) ('a' + u)) << ",";
					}
				}
				cout << "\n";
			}
		}
		
		cout << qtd << " connected components\n";
		cout << "\n";
	}
	return 0;
}
