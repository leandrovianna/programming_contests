#include <bits/stdc++.h>
using namespace std;

const int N = 310;
int64_t cap[N][N], cost[N][N];
vector<int> g[N];
const int INF = 1000000000;
int64_t dist[N];
bool mark[N];
int from[N];

void add_edge(int u, int v, int64_t x, int64_t w) {
    cap[u][v] = x;
    //cap[v][u] = 0;
    cost[u][v] = w;
    //cost[v][u] = -w;
    g[u].push_back(v);
    //g[v].push_back(u);
}

bool spfa(int n, int s, int t) {
    queue <int> q;
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        mark[i] = false;
        from[i] = -1;
    }
    dist[s] = 0;
    mark[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        mark[u] = false;
        for (int i = 0, sz = g[u].size(); i < sz; i++) {
            int v = g[u][i];
            if (cap[u][v] > 0 && dist[v] > dist[u] + cost[u][v]) {
                dist[v] = dist[u] + cost[u][v];
                from[v] = u;
                if (!mark[v]) {
                    mark[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return dist[t] != INF;
}

pair<int64_t, int64_t> mcmf(int n, int s, int t) {
    pair<int64_t, int64_t> ret = {0, 0};
    while (spfa(n, s, t)) {
        int64_t tmp = INF;
        int now = t;
        while (now != s) {
            int pat = from[now];
            tmp = min(tmp, cap[pat][now]);
            now = pat;
        }
        now = t;
        while (now != s) {
            int pat = from[now];
            cap[pat][now] -= tmp;
            cap[now][pat] += tmp;
            now = pat;
        }
        ret.first += tmp;
        ret.second += tmp * dist[t];
    }
    return ret;
}

const int M = 5100;

int main() {
    int x[M], y[M];
    int64_t z[M], d, k;
    int n, m;

    while (cin >> n >> m) {
        memset(cap, 0, sizeof(cap));
        memset(cost, 0, sizeof(cost));

        for (int i = 0; i < m; i++) {
            cin >> x[i] >> y[i] >> z[i];
        }

        cin >> d >> k;

        for (int i = 0; i < m; i++) {
            add_edge(x[i], y[i], k, z[i]);
            add_edge(y[i], x[i], k, z[i]);
        }

        add_edge(0, 1, d, 0);
        add_edge(n, n+1, d, 0);

        auto p = mcmf(n+10, 0, n+1);

        if (p.first != d)
            cout << "Impossible." << endl;
        else
            cout << p.second << endl;
    }

    return 0;
}
