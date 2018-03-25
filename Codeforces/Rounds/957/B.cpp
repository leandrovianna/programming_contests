//Codeforces - Mystical Mosaic - 957B Div2
#include <bits/stdc++.h>
using namespace std;

bool check(set<int> v[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            int equal = 0, diff = 0;

            for (const auto &x : v[i]) {
                if (v[j].count(x))
                    diff++;
                else
                    equal++;
            }

            if (equal != 0 && diff != 0) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);

    const int N = 55;
    set<int> row[N], col[N];

    int n, m;
    char ch;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ch;
            if (ch == '#') {
                row[i].insert(j);
                col[j].insert(i);
            }
        }
    }

    if (check(row, n) && check(col, m))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
