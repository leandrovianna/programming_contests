//Augmenting Path for MCBM
#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> g[N];

int augment(int v, vector<int> &match, vector<bool> &visited) {
	if (visited[v]) return 0;
	visited[v] = true;

	for (size_t i = 0; i < g[v].size(); i++) {
		int u = g[v][i];

		if (match[u] == -1 || augment(u, match, visited)) {
			match[u] = v;
			return 1;
		}
	}

	return 0;
}

int matching(int left_sz, int right_sz) {
	vector<int> match(left_sz + right_sz, -1);
	vector<bool> visited;

	int mcmb = 0;

	for (int i = 0; i < left_sz; i++) {
		visited.assign(left_sz, false);
		mcmb += augment(i, match, visited);
	}

	return mcmb;
}

int main() {
	ios::sync_with_stdio(false);

	return 0;
}
