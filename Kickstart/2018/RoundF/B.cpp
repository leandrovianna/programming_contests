// Kickstart 2018 - Round F - B - Specializing Villages
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int64_t dist[N][N];

void test(int64_t &ans, int64_t &min_dist, int v, int64_t start, int64_t en) {
    for (int mask = start; mask < en; mask++) {
        int64_t l_ans = 0;
        for (int u = 0; u < v; u++) {
            int64_t d = 1e10;
            for (int x = 0; x < v; x++) {
                if (bool(mask & (1 << u)) != bool(mask & (1 << x))) {
                    d = min(d, dist[u][x]);
                }
            }
            l_ans += d;
        }

        if (l_ans < min_dist) {
            ans = 1;
            min_dist = l_ans;
        } else if (l_ans == min_dist) {
            ans++;
        }
    }
}

int main() {
    int t, v, e;

    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        vector<pair<int, int>> g[N];
        cin >> v >> e;
        
        for (int i = 0, a, b, l; i < e; i++) {
            cin >> a >> b >> l;
            a--;
            b--;
            g[a].push_back({b, l});
            g[b].push_back({a, l});
        }

        for (int u = 0; u < v; u++) {
            set<pair<int, int>> q;
            q.insert({0, u});
            memset(dist[u], 0x3f3f3f3f, sizeof(dist[u]));
            dist[u][u] = 0;

            while (q.size() > 0) {
                auto it = q.begin();
                int x = it->second;
                q.erase(it);

                for (const auto &edge : g[x]) {
                    int y = edge.first;
                    if (dist[u][y] > dist[u][x] + edge.second) {
                        dist[u][y] = dist[u][x] + edge.second;
                        q.insert({dist[u][y], y});
                    }
                }
            }
        }

        // mask = subset of vertices that produce fruit

        int64_t ans = 0, min_dist = 1e10;
        int k = min(v, 15);
        test(ans, min_dist, v, 0, 1 << k);

        cout << "Case #" << ti << ": " << ans << "\n";
    }
    return 0;
}
