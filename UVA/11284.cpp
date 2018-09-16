// UVA - Shopping Trip - 11284
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const double INFD = 1e9, EPS = 1e-9;
vector<pair<int, double> > g[N];
double dist[N][N];

void dijkstra(int v) {
    set<pair<double, int> > queue;
    
    queue.insert({0.0, v});

    for (int u = 0; u < N; u++) {
        dist[v][u] = INFD;
    }

    dist[v][v] = 0;

    while (queue.size() > 0) {
        auto p = queue.begin();

        for (const auto &edge : g[p->second]) {
            if (dist[v][edge.first] > dist[v][p->second] + edge.second) {
                dist[v][edge.first] = dist[v][p->second] + edge.second;
                queue.insert({dist[v][edge.first], edge.first});
            }
        }

        queue.erase(p);
    }
}

const int M = 15, V = 1 << M;
double price[M];
int idx[N], cnt, inv[M];
double dp[M][V];
int used[M][V], vis = 0;

double solve(int pos, int visited) {
    double &ans = dp[pos][visited];

    if (used[pos][visited] == vis)
        return ans;

    used[pos][visited] = vis;

    ans = price[pos] - dist[inv[pos]][inv[0]];


    for (int v = 0; v < cnt; v++) {
        if (v != pos && (visited & (1 << v)) == 0) {
            ans = max(ans, price[pos] - dist[inv[pos]][inv[v]] + solve(v, visited | (1 << v)));
        }
    }

    return ans;
}


int main() {
    cout << fixed << setprecision(2);

    int t;
    int n, m, a, b, p;
    double c;

    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int v = 0; v <= n; v++) {
            g[v].clear();
        }

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }

        for (int v = 0; v <= n; v++) {
            dijkstra(v);
        }

        memset(idx, -1, sizeof(idx));
        cnt = 0;
        inv[cnt] = 0;
        idx[0] = cnt++;
        price[0] = 0;

        cin >> p;
        for (int i = 0; i < p; i++) {
            cin >> a >> c;

            if (idx[a] == -1) {
                inv[cnt] = a;
                idx[a] = cnt++;
                price[idx[a]] = 0;
            }

            price[idx[a]] += c;
        }

        vis++;
        double ans = solve(0, 1);

        if (ans < EPS) {
            cout << "Don't leave the house\n";
        } else {
            cout << "Daniel can save $" << ans << "\n";
        }
    }
    return 0;
}
