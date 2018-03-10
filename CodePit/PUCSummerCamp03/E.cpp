//CodePit - A Terra Herdada por Tio Tom - E
//URI - '' - 1330
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int grid[N][N], vis = 1;
vector<int> g[N*N];

struct pack {
	int u, v;
	bool color;
	pack(int u, int v, bool color) : u(u), v(v), color(color) {
	}
};

const int X[] = {0, -1, 0, +1};
const int Y[] = {-1, 0, +1, 0};

vector<int> set1;
bool visited[N][N];

void bfs(int si, int sj, int n, int m) {
	queue<pack> queue;

	queue.push(pack(si, sj, false));

	while (!queue.empty()) {
		int x = queue.front().u;
		int y = queue.front().v;
		bool color = queue.front().color;
		queue.pop();

		if (visited[x][y]) continue;
		visited[x][y] = true;

		int k = x * m + y;

		if (color) {
			set1.push_back(k);
		}

		for (int i = 0; i < 4; i++) {
			int dx = x + X[i];
			int dy = y + Y[i];

			if (0 <= dx && dx < n && 0 <= dy && dy < m) {
				if (grid[dx][dy] != vis) {
					g[k].push_back(dx * m + dy);
					queue.push(pack(dx, dy, !color));
				}
			}
		}
	}
}

vector<bool> seen;
vector<int> match;

int augment(int v) {
	// cout << "^" << v << " -> ";
	if (seen[v]) return 0;
	seen[v] = true;

	for (vector<int>::iterator it = g[v].begin();
			it != g[v].end(); it++) {
		int &u = *it;
		if (match[u] == -1 || augment(match[u])) {
			match[u] = v;
			// cout << "*" << match[u] << endl;
			return 1;
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m, k, x, y;

	while (cin >> n >> m, n && m) {
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			x--;
			y--;
			grid[x][y] = vis;
		}

		for (int i = 0; i < N*N; i++)
			g[i].clear();

		memset(visited, 0, sizeof(visited));
		set1.clear();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j]) {
					bfs(i, j, n, m);
				}
			}
		}

		int mcbm = 0;

		match.assign(n*m, -1);
		seen.assign(n*m, false);

		for (vector<int>::iterator it = set1.begin();
				it != set1.end(); it++) {
			for (vector<int>::iterator it2 = set1.begin();
				it2 != set1.end(); it2++) {
				seen[*it2] = false;
			}

			mcbm += augment(*it);
		}

		cout << mcbm << endl;

		vis++;
	}

	return 0;
}
