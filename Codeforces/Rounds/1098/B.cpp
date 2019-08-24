// Codeforces - Nice Table - 1098B Div1
#include <bits/stdc++.h>
using namespace std;

const int N = 300100;
string table[N], cpy[N], best[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> table[i];
        cpy[i] = table[i];
        best[i] = table[i];
    }

    const string TYPES = "ACGT";

    int answer = 2000000000;
    char p1[2], p2[2];

    for (int mask = 0; mask < (1 << 4); mask++) {
        if (__builtin_popcount(mask) != 2) continue;

        p1[0] = 'X';
        p2[0] = 'X';

        for (int i = 0; i < 4; i++) {
            if (mask & (1 << i)) {
                if (p1[0] == 'X') p1[0] = TYPES[i];
                else p1[1] = TYPES[i];
            } else {
                if (p2[0] == 'X') p2[0] = TYPES[i];
                else p2[1] = TYPES[i];
            }
        }

        int changes = 0;

        for (int j = 0; j < m; j++) {
            char* p = j % 2 == 0 ? p1 : p2;
            int c1 = 0, c2 = 0;

            for (int i = 0; i < n; i++) {
                int k = i % 2, l = (i+1) % 2;
                if (p[k] != table[i][j])
                    c1++;
                if (p[l] != table[i][j])
                    c2++;
            }

            changes += min(c1, c2);

            for (int i = 0; i < n; i++) {
                int k = c1 < c2 ? i % 2 : (i+1) % 2;
                cpy[i][j] = p[k];
            }
        }

        if (answer > changes) {
            answer = changes;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    best[i][j] = cpy[i][j];
                }
            }
        }

        changes = 0;
        for (int i = 0; i < n; i++) {
            char *p = i % 2 == 0 ? p1 : p2;
            int c1 = 0, c2 = 0;

            for (int j = 0; j < m; j++) {
                int k = j % 2, l = (j+1) % 2;
                if (p[k] != table[i][j])
                    c1++;
                if (p[l] != table[i][j])
                    c2++;
            }

            changes += min(c1, c2);
            for (int j = 0; j < m; j++) {
                int k = c1 < c2 ? j % 2 : (j+1) % 2;
                cpy[i][j] = p[k];
            }
        }

        if (answer > changes) {
            answer = changes;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    best[i][j] = cpy[i][j];
                }
            }
        }
    }

    // print answer

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << best[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}
