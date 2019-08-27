// Live Archive - Pascal Library - 3470 - Latin America 2005
#include <bits/stdc++.h>
using namespace std;

const int N = 150, D = 550;
int dinner[D][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;

    while (cin >> n >> d, n || d) {
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dinner[i][j];
            }
        }

        bool yes = false;

        for (int j = 0; j < n; j++) {
            int x = 0;
            for (int i = 0; i < d; i++) {
                x += dinner[i][j];
            }

            if (x == d) {
                yes = true;
                break;
            }
        }

        cout << (yes ? "yes" : "no") << "\n";
    }

    return 0;
}
