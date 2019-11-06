// Codeforces - Road Construction - Jakarta 2019 - 1252L - Solution with MCBM
#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
vector<int> g[N];
int match[N], lmatch[N];
bool visited[N];
 
int augment(int v) {
    assert(0 <= v && v < N);

	if (visited[v]) return 0;
	visited[v] = true;
 
    for (const auto &u : g[v]) {
		if (match[u] == -1) {
			match[u] = v;
			lmatch[v] = u;
			return 1;
		}
	}

    for (const auto &u : g[v]) {
		if (augment(match[u])) {
			match[u] = v;
			lmatch[v] = u;
			return 1;
		}
	}
 
	return 0;
}
 
int matching(int left_sz) {
	memset(match, -1, sizeof(match));
	memset(lmatch, -1, sizeof(lmatch));
 
	int mcmb = 0, m;
	bool keep = true;
 
    while (keep) {
        keep = false;

        for (int i = 0; i < left_sz; i++) {
            visited[i] = false;
        }
        for (int i = 0; i < left_sz; i++) {
            if (lmatch[i] == -1) {
                m = augment(i);
                mcmb += m;
                if (m > 0)
                    keep = true;
            }
        }
    }
 
	return mcmb;
}

const int K = 2010; // maximum of workers
const int R = 2010; // maximum of roads
int getWorker(int i) {
    return i;
}
int getRoad(int i) {
    return K + i;
}

// material to road
unordered_map<int, vector<int>> mat2roads;
pair<int, int> roads[R];
int worker[K];
int ans[K];

int tin[N], low[N];
int timer;
vector<int> adj[N];
set<pair<int, int>> bridges;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int &to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                bridges.insert({v, to});
                bridges.insert({to, v});
            }
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    bridges.clear();
    memset(visited, false, sizeof(visited));
    memset(tin, -1, sizeof(tin));
    memset(low, -1, sizeof(low));
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    for (int i = 0, a, m; i < n; i++) {
        cin >> a >> m;
        for (int j = 0, b; j < m; j++) {
            cin >> b;
            mat2roads[b].push_back(i);
        }
        roads[i] = {i+1, a};
        adj[i].push_back(a-1);
        adj[a-1].push_back(i);
    }
    
    for (int i = 0; i < k; i++) {
        cin >> worker[i];
    }

    find_bridges(n);

    bool result = false;

    for (int i = 0; i < n; i++) {
        int v = roads[i].first-1, u = roads[i].second-1;
        if (bridges.count({v, u}) > 0) {
            continue; // brigdes always are constructed
        }

        for (int q = 0; q < N; q++)
            g[q].clear();

        for (int w = 0; w < k; w++) {
            for (const auto &r : mat2roads[worker[w]]) {
                if (r == i) continue;

                g[getWorker(w)].push_back(getRoad(r));
                g[getRoad(r)].push_back(getWorker(w));
            }
        }

        int mcbm = matching(k);
        if (mcbm >= n-1) {
            result = true;
            break;
        }
    }

    if (result) {
        memset(ans, -1, sizeof(ans));
        for (int i = 0; i < n; i++) {
            if (match[getRoad(i)] != -1) {
                ans[match[getRoad(i)]] = i;
            }
        }
        for (int i = 0; i < k; i++) {
            if (ans[i] == -1)
                cout << "0 0\n";
            else
                cout << roads[ans[i]].first << " " << roads[ans[i]].second << "\n";
        }
    } else {
        cout << "-1\n";
    }

    return 0;
}
