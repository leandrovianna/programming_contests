#include <iostream>
#include <vector>
using namespace std;

const int W = 1;

void dfs(vector<pair<int, int> > g[], long dist[], long comp[], 
		const int n, const int s, const int d) {

	if (s == d)
		return ;

	for (vector<pair<int, int> >::iterator i = g[s].begin(); 
			i < g[s].end(); i++) {
			int new_dist = dist[s] + W;
			int t = i->second;

			if ( (t == 1 && (dist[s] % 3) != 0) ||
					(t == 0 && (dist[s] % 3) == 0)) {
				continue;
			}

			if (dist[i->first] == -1 || 
					(new_dist > dist[i->first] && comp[i->first])) {
				dist[i->first] = dist[s] + W;
				comp[i->first]--;
				dfs(g, dist, comp, n, i->first, d);
			}
	}
}

int main() {
	const int N = 500;
	vector<pair<int, int> > graph[N];		
	long dist[N], comp[N];
	int n, e, s, m;

	cin >> n >> e >> s >> m;
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		graph[a].push_back(make_pair(b, t));
	}

	for (int i = 0; i < n; i++) {
		dist[i] = -1;
		comp[i] = 100;
	}

	dist[e] = 0;

	dfs(graph, dist, comp, n, e, s);

	if (dist[s] == -1)
		cout << '*' << endl;
	else
		cout << dist[s] << endl;

	return 0;
}
