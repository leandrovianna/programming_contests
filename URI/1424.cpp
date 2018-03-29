//URI Online Judge - Problema Fácil de Rujia Liu - 1424
#include <bits/stdc++.h>
using namespace std;

const int N = 1000100; // 10^6
vector<int> pos[N];

int main() {
    ios::sync_with_stdio(false);
    int n, m, x, v;

    while (cin >> n >> m) {
        for (int i = 0; i < N; i++)
            pos[i].clear();

        for (int i = 0; i < n; i++) {
            cin >> x;
            pos[x].push_back(i+1);
        }

        for (int i = 0; i < m; i++) {
            cin >> x >> v;
            if (pos[v].size() < x)
                cout << 0 << "\n";
            else
                cout << pos[v][x-1] << "\n";
        }
    }

    return 0;
}
