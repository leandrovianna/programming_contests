#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
struct Task {
    int s, e;
} tasks[N];

bool overlap(Task t1, Task t2) {
    // intersection is not empty
    return max(t1.s, t2.s) <= min(t1.e-1, t2.e-1);
}

vector<int> g[N];
int color[N];

bool dfs(int v) {
    assert(color[v] != 0);

    for (const auto &u : g[v]) {
        if (color[u] == 0) { // not visited
            color[u] = (color[v] == 1 ? 2 : 1);
            if (!dfs(u)) // if false, not bipartite
                return false;
        } else if (color[u] == color[v]) {
            // not bipartite
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> tasks[i].s >> tasks[i].e;

            // clear graph
            g[i].clear();
            color[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (overlap(tasks[i], tasks[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        bool bipartite = true;
        for (int v = 0; v < n; v++) {
            if (color[v] == 0) { // not visited
                color[v] = 1;
                bipartite = bipartite && dfs(v);
            }
        }

        cout << "Case #" << ti << ": ";
        if (bipartite) {
            for (int v = 0; v < n; v++) {
                cout << (color[v] == 1 ? 'C' : 'J');
            }
            cout << "\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}
