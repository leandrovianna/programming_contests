#include <bits/stdc++.h>
using namespace std;

const int N = 510;
string words[N];

vector<int> g[N];
int color[N];
bool visited[N];

void dfs(int v) {
    visited[v] = true;

    for (const auto &u : g[v]) {
        if (!visited[u]) {
            color[u] = 1 - color[v];
            dfs(u);
        }
    }
}

// Kuhn Matching Algorithm
int match[N], lmatch[N];

int augment(int v) {
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

int matching(int size) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < N; i++) {
        shuffle(g[i].begin(), g[i].end(), rng);
    }

    memset(match, -1, sizeof(match));
    memset(lmatch, -1, sizeof(lmatch));

    int mcmb = 0, m;
    bool keep = true;

    while (keep) {
        keep = false;

        for (int v = 0; v < size; v++) {
            visited[v] = false;
        }

        for (int v = 0; v < size; v++) {
            if (color[v] == 1) continue;

            if (lmatch[v] == -1) {
                m = augment(v);
                mcmb += m;
                if (m > 0)
                    keep = true;
            }
        }
    }

    return mcmb;
}

bool check(int i, int j) {
    bool found = false;
    bool isSwapFree = false;

    char c1, c2;

    for (int k = 0; k < static_cast<int>(words[i].size()); k++) {
        if (words[i][k] != words[j][k]) {
            if (isSwapFree) {
                return false;
            }

            if (found) {
                if (c1 == words[j][k] && c2 == words[i][k]) {
                    isSwapFree = true;
                } else {
                    return false;
                }
            } else {
                found = true;
                c1 = words[i][k];
                c2 = words[j][k];
            }
        }
    }

    return isSwapFree;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (check(i, j)) {
                // cout << words[i] << " <-> " << words[j] << endl;
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    for (int v = 0; v < n; v++) {
        if (!visited[v]) {
            color[v] = 0;
            dfs(v);
        }
    }

    int ans = n - matching(n);

    cout << ans << "\n";

    return 0;
}
