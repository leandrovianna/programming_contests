// HackerRank - A Time-saving Affair - WoC 38
#include <bits/stdc++.h>
using namespace std;

const int N = 10 * 1000 + 10;
const int INF = 1000 * 1000 * 1000 + 10;
vector<pair<int, int> > g[N];
int dist[N];

void dijkstra(int source, int k) {
    for (int i = 0; i < N; i++)
        dist[i] = INF;

    dist[source] = 0;

    multiset<pair<int, int> > q;

    q.insert({0, source});

    while (q.size() > 0) {
        auto p = q.begin();
        int v = p->second, w = p->first;
        q.erase(p);

        //cout << "vertex " << v << " with cost " << w << endl;

        // verify if signal is red
        if ((w / k) & 1) {
            //cout << "incrementing " << k - w % k << endl;
            w += k - w % k; 
        }

        for (const auto &edge : g[v]) {
            int u = edge.first;
            int cost = w + edge.second;

            //cout << "find vertex " << u << " with cost " << cost << endl;

            if (dist[u] > cost) {
                //cout << "minimizing " << dist[u] << endl;
                dist[u] = cost;
                q.insert({cost, u});
            }
        }
    }
}

int main() {
    int n, k, m;

    cin >> n >> k >> m;
    for (int i = 0, x, y, t; i < m; i++) {
        cin >> x >> y >> t;
        g[x].push_back({y, t});
        g[y].push_back({x, t});
    }

    dijkstra(1, k);

    cout << dist[n] << "\n";
    return 0;
}
