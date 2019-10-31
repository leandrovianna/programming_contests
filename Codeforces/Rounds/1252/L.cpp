// Codeforces - Road Construction - ICPC Jakarta 2019
#include <bits/stdc++.h>
using namespace std;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    pair<int, int> idx;
    FlowEdge(int v, int u, long long cap, pair<int, int> idx) : v(v), u(u), cap(cap), idx(idx) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap, pair<int, int> idx = {-1, -1}) {
        edges.push_back(FlowEdge(v, u, cap, idx));
        edges.push_back(FlowEdge(u, v, 0, {-1, -1}));
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

const int N = 2010;
const int M = 10010;
int c[N];
int ans[N];

pair<int, int> roads[N];
vector<int> b[N];

const int source = 0, sink = 1;
int getmaterial(int m) {
    return m + 2;
}
int getroad(int r, int k) {
    return k + 2 + r;
}
Dinic dinic(M + N, source, sink);

bool visited[N];
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

map<int, int> idx;
map<int, vector<int>> material2workers;
int cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;
    for (int v = 0, u, m; v < n; v++) {
        cin >> u >> m;
        roads[v] = {v+1, u};
        adj[v].push_back(u-1);
        adj[u-1].push_back(v);

        for (int i = 0, x; i < m; i++) {
            cin >> x;
            b[v].push_back(x);

            if (idx.count(x) == 0)
                idx[x] = cnt++;
        }
    }

    for (int w = 0; w < k; w++) {
        cin >> c[w];
        material2workers[c[w]].push_back(w);
    }

    find_bridges(n);

    int extra = getroad(n, cnt), nobridgesqtd = 0;
    for (int v = 0; v < n; v++) {
        int u = roads[v].second - 1;
        if (bridges.find({v, u}) == bridges.end()) {
            nobridgesqtd++;
            dinic.add_edge(getroad(v, cnt), extra, 1);
        } else {
            dinic.add_edge(getroad(v, cnt), sink, 1);
        }
    }
    dinic.add_edge(extra, sink, nobridgesqtd-1);

    for (const auto &p : idx) {
        int m = p.second;
        int q = material2workers[p.first].size();

        dinic.add_edge(source, getmaterial(m), q);

        for (int v = 0; v < n; v++) {
            if (binary_search(b[v].begin(), b[v].end(), p.first)) {
                dinic.add_edge(getmaterial(m), getroad(v, cnt), 1, {v, p.first});
            }
        }
    }

    int64_t mf = dinic.flow();

    if (mf >= n-1) {
        memset(ans, -1, sizeof(ans));
        for (const auto &edge: dinic.edges) {
            if (edge.idx.first != -1 && edge.cap == edge.flow) {
                assert(!material2workers[edge.idx.second].empty());

                int w = material2workers[edge.idx.second].back();
                material2workers[edge.idx.second].pop_back();
                ans[w] = edge.idx.first;
            }
        }

        for (int w = 0, x; w < k; w++) {
            x = ans[w];
            if (x == -1)
                cout << "0 0\n";
            else
                cout << roads[x].first << " " << roads[x].second << "\n";
        }

    } else {
        cout << "-1\n";
    }

    return 0;
}
