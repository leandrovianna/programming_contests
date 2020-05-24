// Codeforces - Problemsetting
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

int getcont(int i) {
    return i+1;
}
 
int getprob(int i) {
    return 20 + i;
}
 
const int64_t flow_inf = 1e18;
const int M = 60, N = 20;
vector<int> g[M];
map<string, int> idx;
int qtd[N];
 
int main() {
    ios::sync_with_stdio(false);
    fstream fin("d.in");
 
    const int V = 100;
    const int source = 0, sink = V-1;
 
    int n, m;
    string s, t;
 
    int ti = 1;
    while (fin >> n >> m, n || m) {
        for (int i = 0, x; i < n; i++) {
            fin >> s >> x;
            idx[s] = i;
            qtd[i] = x;
        }

        fin.ignore();
 
        for (int i = 0; i < m; i++) {
            g[i].clear();
            getline(fin, s);
            stringstream ss(s);
            while (ss >> t) {
                g[i].push_back(idx[t]);
            }
        }
 
        int answer = 0;
 
        for (int x = n; x >= 1; x--) {
            bool up = false;
            for (int mask = 0; mask < (1 << n); mask++) {
                if (__builtin_popcount(mask) != x) continue;

                int64_t total = 0;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        total += qtd[i];
                    }
                }

                if (total > m) continue;
 
                Dinic dinic(V, source, sink);
 
                for (int i = 0; i < m; i++) {
                    dinic.add_edge(source, getprob(i), 1);
 
                    for (const auto &u : g[i]) {
                        if (mask & (1 << u)) {
                            dinic.add_edge(getprob(i), getcont(u), flow_inf);
                        }
                    }
                }
 
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        dinic.add_edge(getcont(i), sink, qtd[i]);
                    }
                }
 
                int64_t f = dinic.flow();
                if (f == total) {
                    up = true;
                    break;
                }
            }
 
            if (up) {
                answer = x;
                break;
            }
        }
 
        cout << "Case #" << ti << ": " << answer << "\n";
        ti++;
    }
    return 0;
}
