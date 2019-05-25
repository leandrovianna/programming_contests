// Strongly Connected Components - Kosaraju and Sharir Algorithm
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N], gr[N];
bool used[N];
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;
    for (const auto &u : g[v]) {
        if (!used[u]) {
            dfs1(u);
        }
    }
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (const auto &u : gr[v]) {
        if (!used[u]) {
            dfs2(u);
        }
    }
}

void kosaraju(int n) {
    memset(used, false, sizeof(used));
    for (int v = 0; v < n; v++) {
        if (!used[v]) {
            dfs1(v);
        }
    }

    memset(used, false, sizeof(used));
    component.clear();

    for (int i = 0; i < n; i++) {
        int v = order[n - 1 - i];
        if (!used[v]) {
            dfs2(v);
            cout << "Component:";
            for (const auto &u : component) {
                cout << " " << u;
            }
            cout << endl;
            component.clear();
        }
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y; // x -> y
        g[x].push_back(y);
        gr[y].push_back(x); // reverse graph
    }

    kosaraju(n);
    return 0;
}
