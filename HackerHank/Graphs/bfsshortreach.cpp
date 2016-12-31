#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int W = 6;

void bfs(vector<int> g[], int dist[], const int n, const int s) {
	int fila[1000], tam = 0;
	bool add;
	
	for (int i = 0; i < n; i++) dist[i] = -1;
	
	fila[tam++] = s;
	dist[s] = 0;

	while (tam > 0) {
		int f = fila[tam-1];
		tam--;

		for (vector<int>::iterator i = g[f].begin(); i < g[f].end(); i++) {
			int new_dist = dist[f] + W;
			if (dist[*i] == -1 || new_dist < dist[*i]) {
				fila[tam++] = *i;
				dist[*i] = dist[f] + W;
			}
		}
	}
}

int main() {
	const int N = 1000;	
	vector<int> graph[N];
	int q, n, m, u, v, s, dist[N];

	cin >> q;
	for (int qi = 0; qi < q; qi++) {
		for (int i = 0; i < N; i++) {
			graph[i].clear();
			dist[i] = -1;
		}

		cin >> n >> m;
		for (int mi = 0; mi < m; mi++) {
			cin >> u >> v;
			u--;
			v--;
			if (find(graph[u].begin(), graph[u].end(), v) == graph[u].end()) 
				graph[u].push_back(v);

			if (find(graph[v].begin(), graph[v].end(), u) == graph[v].end()) 
				graph[v].push_back(u);
		}

		cin >> s;
		s--;

		bfs(graph, dist, n, s); // bfs starts in node s

		for (int i = 0; i < n; i++) {
			if (i != s) {
				cout << dist[i];
				if (i != n-1)
					cout << ' ';
			}

		}
		cout << endl;
	}
	return 0;
}
