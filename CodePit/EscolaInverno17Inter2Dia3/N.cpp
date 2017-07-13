#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

typedef pair<int, int> ii;
typedef pair<i64, int> li;
typedef pair<i64, i64> ll;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int N = 1e5+10;
const i64 INF = 1e18;

vll g[N];
i64 dist[N];

void dijkstra(int s, int n) {
	bool visited[N];

	for (int i = 0; i < n; i++) {
		dist[i] = INF;
		visited[i] = false;
	}
	dist[s] = 0;
	
	priority_queue<ll, vll, greater<ll> > pq;
	pq.push( ll(dist[s], s) );

	ll atual;
	
	while (!pq.empty()) {
		atual = pq.top();
		pq.pop();

		i64 w = atual.first; 
		int v = atual.second;

		if (visited[v]) 
			continue;

		visited[v] = true; 

		for (vll::iterator it = g[v].begin(); it != g[v].end(); ++it) {
			if (!visited[it->first] && dist[it->first] > w + it->second) { 
				dist[it->first] = w + it->second;
				pq.push(ll(dist[it->first], it->first));
			}
		}
	}
}

int main() {
	int n, a, q, s, t;
	i64 l;
	
	while (cin >> n, n) {
		for (int i = 0; i < n; i++)
			g[i].clear();
		
		for (int i = 1; i <= n-1; i++) {
			cin >> a >> l;

			g[i].push_back(ll(a, l));
			g[a].push_back(ll(i, l));
		}

		cin >> q;
		for (int i = 0; i < q; i++) {
			cin >> s >> t;

			dijkstra(s, n);
			cout << dist[t];

			if (i != q-1) cout << " ";
		}
		cout << endl;
	}

	return 0;
}
