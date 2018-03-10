//CodePit - Even Obsession - A
#include <bits/stdc++.h>
using namespace std;

const int N = 10100;
int n, m;
struct no {
	int u, w, e;
	no(int u, int w, int e) : u(u), w(w), e(e) {}
};

bool operator<(no a, no b) {
	return a.w > b.w;
}

vector<pair<int, int>> g[N];
const int PAR = 0, IMPAR = 1;
int dist[N][2];
bool vis[N][2];

void djikstra(int s) {
	memset(dist, -1, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	dist[s][PAR] = 0;
	priority_queue<no> queue;
	queue.push(no(s, 0, 0));

	while (!queue.empty()) {
		int v = queue.top().u;
		int w = queue.top().w;
		int e = queue.top().e;
		queue.pop();

		if (vis[v][e & 1]) continue;
		vis[v][e & 1] = true;

		int f = (e + 1) & 1;
		for (const auto &u : g[v]) {
			if (dist[u.first][f] == -1
					|| w + u.second < dist[u.first][f]) {
				dist[u.first][f] = w + u.second;
				queue.push(no(u.first, w + u.second, e + 1));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	int a, b, w;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}

	djikstra(1);

	int ans = dist[n][PAR];
	cout << ans << endl;

	return 0;
}
