// TAP 2018/2 - G4 - Gasolina
#include <bits/stdc++.h>
using namespace std;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
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

    void add_edge(int v, int u, long long cap) {
        edges.push_back(FlowEdge(v, u, cap));
        edges.push_back(FlowEdge(u, v, 0));
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

const int E = 20100;
int edges[E][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int p, r, c;
    int s, t;

    cin >> p >> r >> c;

    s = p + r;
    t = p + r + 1;

    Dinic dinic(p+r+2, s, t);

    int64_t max_flow = 0;
    for (int i = 0, d; i < p; i++) {
        cin >> d;
        max_flow += d;
        dinic.add_edge(r+i, t, d);
    }

    for (int i = 0, e; i < r; i++) {
        cin >> e;
        dinic.add_edge(s, i, e);
    }

    for (int i = 0, ri, pi, ti; i < c; i++) {
        cin >> pi >> ri >> ti;
        edges[i][0] = r+pi-1;
        edges[i][1] = ri-1; 
        edges[i][2] = ti;
    }

    int lo = 1, hi = 1000 * 1000, mid, ans = -1;

    while (lo <= hi) {
        mid = (lo + hi) / 2;
        Dinic dinic2 = dinic;
        for (int i = 0; i < c; i++) {
            if (edges[i][2] <= mid) {
                dinic2.add_edge(edges[i][1], edges[i][0], 1e9);
            }
        }

        int64_t flow = dinic2.flow();
        if (flow == max_flow) {
            ans = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    cout << ans << "\n";

    return 0;
}
