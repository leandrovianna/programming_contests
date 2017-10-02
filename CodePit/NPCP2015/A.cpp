#include <iostream>
#include <iomanip>
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

const int N = 1e5+10;

int n; // number of vertex
vector<int> g[N]; // adj. list

array<bool, N> vis;
array<int, N> dist;

void dfs(int v, int p) {
	vis[v] = true;

	for (auto &u : g[v]) {
		if (u == p) continue;

		if (!vis[u]) {
			dist[u] = dist[v] + 1;
			dfs(u, v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int a, b, l;

	cin >> n >> l;
	for (int i = 0; i < l; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vis.fill(false);
	int ans = 0;
	
	vector<int> radius;

	// for each vertex of the forest
	for (int i = 0; i < n; i++) {
		// cout << vis[i] << " " << i << endl;
		if (!vis[i]) {
			dist.fill(0);
			dfs(i, -1);

			// further vertex 
			int w = distance(dist.begin(), 
					max_element(dist.begin(), dist.end()));


			dist.fill(0);
			vis.fill(false);
			dfs(w, -1);

			int d = *max_element(dist.begin(), dist.end()); 
			int r = (d % 2 == 0) ? ((d + 1) / 2) : (d / 2);

			ans = max(ans, d);
			radius.push_back(r);
		}
	}

	sort(radius.begin(), radius.end(), greater<int>());

	if (radius.size() > 1)
		ans = max(ans,
				radius[0] + radius[1] + 1);
	if (radius.size() > 2)
		ans = max(ans,
				radius[1] + radius[2] + 2);

	cout << ans << endl;
	return 0;
}
