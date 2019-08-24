// Codeforces - Lunar New Year and a Wander - 1106D
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> graph[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<int> answer;
    set<int> neighboors = {1};

    while (!neighboors.empty()) {
        auto it = neighboors.begin();
        
        vis[*it] = true;
        answer.push_back(*it);

        for (const auto &u : graph[*it]) {
            if (!vis[u]) {
                neighboors.insert(u);
            }
        }

        neighboors.erase(it);
    }

    for (const auto &u : answer) {
        cout << u << " ";
    }

    cout << "\n";
    return 0;
}
