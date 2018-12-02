#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m;
char g[N][N];

bool full(int i, int j) {
    return g[i][j] == '#';
}

bool test(int i, int j) {
    bool ans = false;
    ans |= full(i, j+1) && full(i+1, j) /*&& !full(i+1, j+1)*/;
    ans |= full(i, j-1) && full(i, j+1) && full(i+1, j-1) && /*!full(i+1, j) &&*/ full(i+1, j+1);
    ans |= full(i, j-1) && full(i+1, j)/* && !full(i+1, j-1)*/;
    ans |= full(i-1, j) && full(i-1, j+1)/* && !full(i, j+1)*/ && full(i+1, j) && full(i+1, j+1);
    ans |= full(i-1, j) && full(i-1, j-1) /*&& !full(i, j-1)*/ && full(i+1, j) && full(i+1, j-1);
    ans |= full(i, j-1) && full(i, j+1) && full(i-1, j-1) /*&& !full(i-1, j)*/ && full(i-1, j+1);
    ans |= full(i-1, j) && full(i, j+1) /*&& !full(i-1, j+1)*/;
    ans |= full(i-1, j) /*&& !full(i-1, j-1)*/ && full(i, j-1);
    return ans;
}

int main() {
    
    cin >> n >> m;

    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= m+1; j++) {
            if (i == 0 || j == 0 || i == n+1 || j == m+1)
                g[i][j] = '.';
            else
                cin >> g[i][j];
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '#') {
                bool ok = test(i, j);
                if (!ok) {
                    cout << i << " " << j << endl;
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }

    cout << "YES\n";
    return 0;
}
