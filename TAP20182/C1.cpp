// TAP 2018/2 - C1 - Pollution Simulation
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int EMPTY = -1, FULL = 30000;
int grid[N][N];
const int I[] = {-1, 0, +1, 0};
const int J[] = {0, -1, 0, +1};

void bfs(vector<pair<int, int> > poll, int n, int m) {
    queue<pair<pair<int, int>, int> > q;

    for (const auto p : poll) {
        q.push({p, 0});
    }

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        if (grid[p.first.first][p.first.second] > 0)
            continue;

        grid[p.first.first][p.first.second] = p.second;
        
        for (int i = 0; i < 4; i++) {
            int di = p.first.first + I[i];
            int dj = p.first.second + J[i];

            if (0 <= di && di < n && 0 <= dj && dj < m) {
                if (grid[di][dj] == EMPTY) {
                    q.push({{di, dj}, p.second+1});
                }
            }
        }
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    vector<pair<int, int> > poll;
    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
           cin >> ch; 
           if (ch == '*')
               grid[i][j] = FULL;
           else if (ch == '-') {
               grid[i][j] = EMPTY;
           } else if (ch == 'P') {
               grid[i][j] = 0;
               poll.push_back({i, j});
           }
        }
    }

    bfs(poll, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == FULL)
                cout << '*';
            else if (grid[i][j] == EMPTY)
                cout << '.';
            else
                cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}
