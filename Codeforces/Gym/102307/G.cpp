// Codeforces - Graduation - 102307G - Univ. Nacional Colombia 2019
#include <bits/stdc++.h>
using namespace std;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int N = 10010, inf = 1e9;
int to[N], sz[N], din[N], cnt[N];
vector<int> dep[N];

bool vis[N];
vector<int> ans;

void dfs(int v) {
    vis[v] = true;
    if (to[v] != -1) {
        if (!vis[to[v]]) {
            dfs(to[v]);
        }
    }
    ans.push_back(v);
}

void topological_sort(int n) {
    memset(vis, false, sizeof(vis));
    for (int v = 0; v < n; v++) {
        if (!vis[v]) {
            dfs(v);
        }
    }

    reverse(ans.begin(), ans.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        to[i] = -1;
        din[i] = 0;
        cnt[i] = 0;
    }

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x == 0) {
            continue;
        } else {
            x--;
        }

        to[i] = x;
        din[x]++;
        cnt[x]++;
        dep[x].push_back(i);
    }

    topological_sort(n);

    for (int i = n-1; i >= 0; i--) {
        int v = ans[i];

        if (to[v] == -1) {
            sz[v] = 0;
        } else {
            sz[v] = 1 + sz[to[v]];
        }
    }

    priority_queue<pair<int, int>> pq;

    for (int v = 0; v < n; v++) {
        if (din[v] == 0) {
            pq.push({sz[v], v});
        }
    }

    int semester = 0, acc = k;
    vector<int> aux;

    while (!pq.empty()) {
        while (!pq.empty() && acc > 0) {
            auto p = pq.top();
            pq.pop();

            int v = p.second;

            if (to[v] != -1) {
                cnt[to[v]]--;

                if (cnt[to[v]] == 0) {
                    aux.push_back(to[v]);
                }
            }

            acc--;
        }

        for (const auto &u : aux) {
            pq.push({sz[u], u});
        }
        aux.clear();

        if (acc < k) {
            semester++;
            acc = k;
        }
    }

    cout << semester << "\n";

    return 0;
}
