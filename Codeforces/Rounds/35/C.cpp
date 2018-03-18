//Codeforces - Fire Again - 35C Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int burning[N][N];

int main() {
    ifstream ifs("input.txt");
    ofstream ofs("output.txt");

    const int X[] = {+0, +1, +0, -1, -1, +1, -1, +1};
    const int Y[] = {+1, +0, -1, +0, -1, +1, +1, -1};

    int n, m;
    int x, y;
    int d;
    ifs >> n >> m;

    queue<tuple<int, int, int> > q;
    int k;
    ifs >> k;
    for (int i = 0; i < k; i++) {
        ifs >> x >> y;
        x--;
        y--;
        q.push({x, y, 1});
        burning[x][y] = 1;
    }

    auto ans = make_tuple(0,0,0);

    while (!q.empty()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        d = get<2>(q.front());

        // cout << x << " " << y << " " << d << endl;

        if (get<2>(ans) < d) {
            ans = q.front();
        }

        q.pop();

        for (int i = 0; i < 4; i++) {
            int xd = x + X[i];
            int yd = y + Y[i];

            if (0 <= xd && xd < n && 0 <= yd && yd < m
                    && burning[xd][yd] == 0) {
                burning[xd][yd] = d+1;
                q.push({xd, yd, d+1});
            }
        }
    }

    ofs << get<0>(ans) + 1 << " " << get<1>(ans) + 1 << endl;

    ifs.close();
    ofs.close();

    return 0;
}
