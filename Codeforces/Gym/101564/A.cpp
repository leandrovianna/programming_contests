// Codeforces - Lawn mower
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
double px[N], py[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nx, ny;
    double w;

    while (cin >> nx >> ny >> w, nx || ny || w) {
        for (int i = 0; i < nx; i++) {
            cin >> px[i];
        }
        for (int i = 0; i < ny; i++) {
            cin >> py[i];
        }

        sort(px, px+nx);
        sort(py, py+ny);

        bool fill1 = true;
        for (int i = 1; i < nx; i++) {
            if (px[i] - px[i-1] > w) {
                // cout << px[i-1] << " " << px[i] << endl;
                fill1 = false;
                break;
            }
        }

        if (150.0 - 2*px[nx-1] > w) {
            fill1 = false;
        }

        bool fill2 = true;
        for (int i = 1; i < ny; i++) {
            if (py[i] - py[i-1] > w) {
                // cout << py[i-1] << " " << py[i] << endl;
                fill2 = false;
                break;
            }
        }

        if (200.0 - 2*py[ny-1] > w) {
            fill2 = false;
        }

        if (fill1 && fill2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
