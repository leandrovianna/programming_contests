// Codeforces - Queen - 1143C Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N];
int c[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    
    cin >> n;

    for (int i = 0, p, ci; i < n; i++) {
        cin >> p >> ci;
        if (p != -1)
            g[p-1].push_back(i);
        c[i] = ci;
    }

    set<int> answer;
    
    for (int v = 0; v < n; v++) {
        if (c[v] == 0) continue;

        bool count_vertex = true;
        for (const auto &u : g[v]) {
            if (c[u] == 0) {
                count_vertex = false;
                break;
            }
        }

        if (count_vertex) {
            answer.insert(v+1);
        }
    }

    if (answer.empty()) {
        cout << "-1";
    }

    for (const auto &v : answer) {
        cout << v << " ";
    }

    cout << "\n";
    return 0;
}
