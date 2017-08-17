#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <limits>
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
const int L = 15; //log N
const i64 INF = numeric_limits<long long>::max();

vll g[N];
i32 nivel[N];
i32 pai[N];
i32 ancestral[N][L];
i64 dist[N];

void dfs(int s) {

	for (vll::iterator it = g[s].begin();
			it != g[s].end(); it++) {
		if (nivel[it->first] == -1) {
			pai[it->first] = s;
			nivel[it->first] = nivel[s] + 1;
			dfs(it->first);
		}
	}

}

int lca(int a, int b) {

	while (a != b) {
		if (nivel[a] > nivel[b]) a = pai[a];
		else b = pai[b];
	}

	return a;
	// if (nivel[a] < nivel[b]) swap(a, b);
    //
	// for (int i = L-1; i >= 0; i--)
	// 	if (nivel[a] - (1<<i) >= nivel[b])
	// 		a = ancestral[a][i];
    //
	// if (a == b) return a;
    //
	// for (int i = L-1; i >= 0; i--)
	// 	if (ancestral[a][i] != -1 && ancestral[a][i] != ancestral[b][i]) {
	// 		a = ancestral[a][i];
	// 		b = ancestral[b][i];
	// 	}
    //
	// return ancestral[a][0];
}

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

		if (visited[v]) continue;
		visited[v] = true;

		for (vll::iterator it = g[v].begin(); it != g[v].end(); ++it) {
			if (dist[it->first] > w + it->second) { 
				dist[it->first] = w + it->second;
				pq.push(ll(dist[it->first], it->first));
			}
		}
	}
}

int main() {
	int n, a, q, s, t;
	i64 l;
	// ios::sync_with_stdio(false);

	while (cin >> n, n) {
		for (int i = 0; i < n; i++)
			g[i].clear();
		
		for (int i = 1; i <= n-1; i++) {
			// cin >> a >> l;
			scanf("%d %lld", &a, &l);

			g[i].push_back(ll(a, l));
			g[a].push_back(ll(i, l));
		}

		// vamos considerar 0 como a raiz

		memset(nivel, -1, sizeof(nivel));
		pai[0] = 0;
		nivel[0] = 0; // nivel da raiz é 0
		dfs(0); // chama dfs para preencher o nivel
		dijkstra(0, n);
		
		for (int i = 0; i < N; i++)
			memset(ancestral[i], -1, sizeof(ancestral[i]));

		for (int i = 0; i < n; i++)
			ancestral[i][0] = pai[i];
		
		for (int j = 0; j < L; j++)
			for (int i = 0; i < n; i++)
				if (ancestral[i][j-1] != -1)
					ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];

		// cin >> q;
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			// cin >> s >> t;
			scanf("%d %d", &s, &t);
			
			i64 r = dist[s] + dist[t] - 2 * dist[lca(s,t)];
			// cout << r;
			printf("%lld", r);

			if (i != q-1) printf(" ");
		}
		printf("\n");
	}

	return 0;
}
