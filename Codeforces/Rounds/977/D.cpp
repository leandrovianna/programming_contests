#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int64_t a[N];
bool vis[N];
vector<int64_t> sq;
vector<int> g[N];

void dfs(int v) {
    //cout << "visiting " << a[v] << endl;
    sq.push_back(v);
    vis[v] = true;

    for (const auto &u : g[v]) {
        if (vis[u] == false) {
            dfs(u);
        }
    }
}

int main() {
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;

            if (a[i] * 2LL == a[j] ||
                    (a[i] % 3LL == 0LL 
                        && a[i] / 3LL == a[j])) {
                //cout << a[i] << " -> " << a[j] << endl;
                g[i].push_back(j);
            }
        }
    }

    for (int v = 0; v < n; v++) {
        memset(vis, 0, sizeof(vis));
        sq.clear();
        //cout << "start from " << a[v] << endl;
        dfs(v);
        bool visall = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false) {
                visall = false;
                break;
            }
        }

        if (visall) {
            for (size_t i = 0; i < sq.size(); i++) {
                cout << a[sq[i]];
                if (i == sq.size()-1)
                    cout << endl;
                else
                    cout << " ";
            }
            break;
        }
    }

    return 0;
}
