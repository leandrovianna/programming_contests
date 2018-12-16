// Live Archive - Telecommunication Partners - Nacional 2003
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
set<int> g[N];
bool vis[N];

set<pair<int, int>> ss;

int cnt;
void dfs(int v) {
	vis[v] = true;
	cnt++;
	//ss.insert({g[v].size(), v});
	
	for (const auto &u : g[v]) {
		if (vis[u] == false) {
			dfs(u);
		}
	}
}

int solve(int k) {
	int u;
	
	while (ss.size() > 0) {
		auto it = ss.begin();
		
		if (it->first < k) {
			u = it->second;
			ss.erase({g[u].size(), u});
			for (const auto &w : g[u]) {
				ss.erase({g[w].size(), w});
				g[w].erase(u);
				ss.insert({g[w].size(), w});
			}
			g[u].clear();
			vis[u] = true; // mark to dfs dont count u
			
		} else {
			break;
		}
	}
	
	return ss.size();
}

int main() {
	int n, p, k, x, y;
	
	while (cin >> n >> p >> k, n) {
		for (int i = 0; i <= n; i++) {
			vis[i] = false;
			g[i].clear();
		}
		
		for (int i = 0; i < p; i++) {
			cin >> x >> y;
			g[x].insert(y);
			g[y].insert(x);
		}
		
		int ans = 0;
		ss.clear();
		for (int i = 1; i <= n; i++) {
			ss.insert({g[i].size(), i});
        }
		solve(k);

		for (int i = 1; i <= n; i++) {
            if (vis[i] == false) {
                cnt = 0;
                dfs(i);
                ans = max(ans, cnt);
            }
		}
		
		cout << ans << "\n";
	}
	return 0;
}
