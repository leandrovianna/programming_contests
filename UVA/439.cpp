//UVa - Knight Moves - 439
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int bfs(pair<int, int> source, pair<int, int> dest) {
    queue<pair<ii, int> > q;
    map<ii, bool> vis;

    q.push({source, 0});

    while (!q.empty()) {
        ii cell = q.front().first;
        int d = q.front().second;
        q.pop();

        if (vis[cell])
            continue;
        vis[cell] = true;

        if (cell == dest)
            return d;

        for (auto p : vector<ii>{{1,2}, {-1,2}, {1,-2}, {-1,-2}}) {
            for (int k = 0; k < 2; k++) {
                swap(p.first, p.second);
                int di = p.first + cell.first;
                int dj = p.second + cell.second;
                
                if (1 <= di && di <= 8 && 1 <= dj && dj <= 8) {
                    q.push({{di, dj}, d+1});
                }
            }
        }
    }

    return 0;
}

int main() {
    char c1, c2;
    int r1, r2;

    while (cin >> c1 >> r1 >> c2 >> r2) {
        cout << "To get from " << c1 << r1 << " to "
            << c2 << r2 << " takes " 
            << bfs({r1, c1 - 'a' + 1}, {r2, c2 - 'a' + 1})
            << " knight moves." << endl;
    }
    return 0;
}
