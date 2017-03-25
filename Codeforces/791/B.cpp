#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define N 150000

typedef vector<int> vii;

vii g[N];
int comp[N];

bool dfs(int v) {
	int n;
	for (int i = 0; i < g[v].size(); i++) {
		n = g[v][i];
		if (comp[n] == -1) {
			comp[n] = comp[v];
			if (g[n].size() != g[v].size()) {
				return false;
			}

			dfs(n);
		}
	}

	return true;
}

int main() {
	int n, m, a, b, label;

	cin >> n >> m;

	memset(comp, -1, sizeof(comp));

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	label = 1;

	for (int i = 0; i < n; i++) {
		if (g[i].size() > 0) {
			comp[i] = label++;
			if (!dfs(i)) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;
	return 0;
}
