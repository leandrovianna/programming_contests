//Puc Summer Camp 2018
//URI - Max, o Louco - 1529
#include <bits/stdc++.h>
using namespace std;

struct edge {
	int v, c, t;
	edge(int v, int c, int t) : v(v), c(c), t(t) {}
};

const int N = 20, T = 55, INF = 1000000000;
vector<edge> g[N];
int cost[N];
int dist[N][T];

bool operator<(edge a, edge b) {
	return a.c < b.c;
}

void djikstra(int source, int maxtank) {
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<edge> queue;

	queue.push(edge(source, 0, maxtank));
	dist[source][maxtank] = 0;

	while (!queue.empty()) {
		edge e = queue.top();
		queue.pop();

		for (vector<edge>::iterator it = g[e.v].begin();
				it != g[e.v].end(); it++) {
			int u = it->v;
			int w = it->c;

			int tank, newcost;
			for (int lt = 0; lt <= maxtank - e.t; lt++) {
				tank = e.t + lt;

				if (tank < w) continue;

				newcost = e.c + lt * cost[e.v];

				if (newcost < dist[u][tank - w]) {
					dist[u][tank - w] = newcost;
					queue.push(edge(u, newcost, tank - w));
				}
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);

	int n, m, t;
	int a, b, c;

	while (cin >> n >> m >> t, n || m || t) {
		for (int i = 0; i < n; i++)
			g[i].clear();

		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			a--;
			b--;

			g[a].push_back(edge(b, c, 0));
			g[b].push_back(edge(a, c, 0));
		}

		for (int i = 0; i < n; i++)
			cin >> cost[i];

		djikstra(0, t);

		int ans = INF;
		for (int j = 0; j <= t; j++) {
			if (dist[n-1][j] != -1) {
				ans = min(ans, dist[n-1][j]);
			}
		}

		cout << (ans == INF ? -1 : ans) << endl;
	}

	return 0;
}
