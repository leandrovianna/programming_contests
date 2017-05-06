#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define N 100000

typedef pair<int, int> ii;
typedef vector<ii> vii;

void bfs(vector<vii> g, int s, int comp[]) {
	queue<ii> q;
	q.push(make_pair(s, 0));

	while (!q.empty()) {
		int v = q.front().first;
		q.pop();

		for (vii::iterator it = g[v].begin(); it != g[v].end(); it++) {
			if (comp[it->first] == -1) {
				comp[it->first] = comp[v];
				q.push(make_pair(it->first, 0));
			}
		}
	}
}

int main() {
	int n, m, a, b;
	int p[N];
	int comp[N];
	vector<vii> g;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	g.resize(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		g[a].push_back(make_pair(b, 0));
		g[b].push_back(make_pair(a, 0));
	}

	int label = 1;
	memset(comp, -1, sizeof(comp));
	for (int i = 0; i < n; i++) {
		if (comp[i] == -1) {
			comp[i] = label++;
			bfs(g, i, comp);
		}
	}

	bool res = true;
	int sum[N];
	memset(sum, 0, sizeof(sum));
	for (int i = 0; i < n; i++) {
		sum[comp[i]] += p[i];
	}

	for (int i = 0; i < n; i++) {
		if (sum[i] < 0) {
			res = false;
			break;
		}
	}

	cout << (res ? "POSSIBLE" : "IMPOSSIBLE") << endl;

	return 0;
}
