// Codeforces - Serval and Toy Bricks - 1153B Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, h;

    cin >> n >> m >> h;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0, x; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            if (x) {
                cout << min(a[j], b[i]) << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }

    return 0;
}
