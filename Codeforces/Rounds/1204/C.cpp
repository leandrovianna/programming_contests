// Codeforces - 1204C - Anna, Svyatoslav and Maps
#include <bits/stdc++.h>
using namespace std;

const int N = 110, inf = 1e9;
int dist[N][N];
bool adj[N][N];
const int M = 1000100;
int p[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    char ch;

    cin >> n;
    for (int v = 1; v <= n; v++) {
        for (int u = 1; u <= n; u++) {
            cin >> ch;
            dist[v][u] = ch == '1' ? 1 : inf;
        }
        dist[v][v] = 0;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    for (int v = 1; v <= n; v++) {
        for (int u = 1; u <= n; u++) {
            for (int q = 1; q <= n; q++) {
                dist[u][q] = min(dist[u][q], dist[u][v] + dist[v][q]);
            }
        }
    }

    vector<int> answer;
    answer.push_back(p[0]);
    for (int i = 1; i < m-1; i++) {
        /*
        cout << dist[answer.back()][p[i+1]] 
            << " (" << answer.back() << ", " << p[i+1] << ")" << endl;
        cout << dist[answer.back()][p[i]] 
            << " (" << answer.back() << ", " << p[i] << ")" << endl;
        */

        if (dist[answer.back()][p[i+1]] != dist[answer.back()][p[i]] + 1) {
            answer.push_back(p[i]);
        }
    }
    answer.push_back(p[m-1]);

    cout << answer.size() << "\n";
    for (const auto &x : answer) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
