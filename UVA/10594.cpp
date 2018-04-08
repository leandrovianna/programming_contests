#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
 
const int
	MAXN = 502,
	MAXE = 100000,
	oo = (int)1e9;
 
int T, V, L, E;
int src, snk, sol;
int cant[MAXN];
int best[MAXN];
int from[MAXN];
int head[MAXN];
struct edge {
	int u, v, w, cap, next;
} edges[MAXE];
 
void add_edge( int u, int v, int w, int cap ) {
	cout << u << " -> " << v << " w: " << w << " cap: " << cap << endl;

	edges[E++] = (edge){ u, v, +w, cap, head[u] };
	head[u] = E - 1;
	edges[E++] = (edge){ v, u, -w, 0, head[v] };
	head[v] = E - 1;
}
 
bool augment( int src, int snk ) {
 
	fill( best, best + V + 2, oo );
	best[src] = 0;
	
    //queue< int> Q;
	//set<pair<int,int> >Q;
	 priority_queue<pair<int, int>, vector<pair<int, int> >,
                                greater<pair<int, int> > > Q;
	Q.push(make_pair(0,src));
	while(!Q.empty())
	{
		int u = Q.top().second;
		//Q.erase(Q.begin())
		Q.pop();
		for ( int e = head[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
		      if ( edges[e].cap && best[u] + edges[e].w < best[v] ) {
				best[v] = best[u] + edges[e].w;
				
				Q.push(make_pair(best[v],v));
				
				from[v] = e;
			}
		}
	}
	
	if ( best[snk] == oo )
	      return false;
	      
	sol += best[snk];
	for ( int x = snk; x != src; x = edges[ from[x] ].u ) {
		edges[ from[x] ].cap--;
		edges[ from[x]^1 ].cap++;
	}
	      
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m, a, b;
	int d, k, c;

	vector<tuple<int, int, int>> es;

	while (cin >> n >> m) {
		E = 0;
		es.clear();
		memset(head,-1,sizeof(head));

		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			es.push_back({a,b,c});
		}

		cin >> d >> k;

		for (auto &t : es) {
			c = get<2>(t);
			add_edge(get<0>(t), get<1>(t), c, k);
			add_edge(get<1>(t), get<0>(t), c, k);
		}

		src = 0;
		snk = n;
	
		add_edge(src, 1, 0, d);

		while (augment(src, snk));

		cout << sol << endl;
	}

	return 0;
}
