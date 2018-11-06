#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int cnt = 0;
int l, w;
char grid[N][N];
int comp[N][N], qtd[N*N];
const int I[] = {+0, -1, -1, +1, +0, +1, -1, +1};
const int J[] = {-1, -1, +0, +1, +1, +0, +1, -1};

void dfs(int i, int j) {
    comp[i][j] = cnt;
    qtd[cnt]++;

    for (int k = 0; k < 8; k++) {
        int di = I[k] + i;
        int dj = J[k] + j;
        if (0 <= di && di < l && 0 <= dj && dj < w
                && grid[di][dj] == 'P' && comp[di][dj] == 0) {
            dfs(di, dj);
        }
    }
}

int main() {
    cin >> l >> w;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 'P' && comp[i][j] == 0) {
                cnt++;
                dfs(i, j);
            }
        }
    }

    int largest = 0;
    for (int i = 0; i < N*N; i++) {
        largest = max(largest, qtd[i]);
    }

    int g = 1000*1000+10, sz = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '-') {
                set<int> groups;
                for (int k = 0; k < 8; k++) {
                    int di = I[k] + i;
                    int dj = J[k] + j;
                    if (0 <= di && di < l && 0 <= dj && dj < w
                            && grid[di][dj] == 'P') {
                        groups.insert(comp[di][dj]);
                    }
                }

                int new_g = cnt - (int) groups.size() + 1;
                int new_sz = 1; // count the mingler
                for (const auto &x : groups)
                    new_sz += qtd[x];

                if (new_sz > largest)
                    continue;

                if (new_g < g) {
                    g = new_g;
                    sz = new_sz;
                } else if (new_g == g) {
                    sz = max(sz, new_sz);
                }
            }
        }
    }

    if (sz == 0) {
        sz = largest+1;
        g = cnt;
    }

    cout << "I can make there be " << g << " total groups"
        << " by forming a group of size " << sz << "." << endl;

    return 0;
}
