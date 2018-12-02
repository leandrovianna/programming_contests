// Codeforces - Labyrinth - 1064D Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
char grid[N][N];
bool vis[N][N];

struct state {
    int i, j;
    int left, right; // remaining moves
};

bool operator<(const state &s1, const state &s2) {
    return (s1.left + s1.right) < (s2.left + s2.right);
}

const int I[] = {+0, -1, +0, +1};
const int J[] = {-1, +0, +1, +0};

void bfs(int r, int c, int n, int m, int x, int y) {
    priority_queue<state> q;
    q.push({r, c, x, y});

    while (!q.empty()) {
        auto st = q.top();
        q.pop();

        if (vis[st.i][st.j])
            continue;
        vis[st.i][st.j] = true;

        for (int k = 0, di, dj; k < 4; k++) {
            if (k == 0 && st.left <= 0)
                continue;

            if (k == 2 && st.right <= 0)
                continue;

            di = st.i + I[k];
            dj = st.j + J[k];

            if (0 <= di && di < n && 0 <= dj && dj < m 
                    && grid[di][dj] == '.') {
                auto st2 = state{di, dj, st.left, st.right};
                if (k == 0)
                    st2.left--;
                if (k == 2)
                    st2.right--;
                q.push(st2);
            }
        }
    }
}

int main() {
    int n, m, r, c, x, y;

    cin >> n >> m >> r >> c >> x >> y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    bfs(r-1, c-1, n, m, x, y);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j])
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
