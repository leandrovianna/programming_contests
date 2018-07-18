#include <bits/stdc++.h>
using namespace std;

double dist(int x0, int y0, int x1, int y1) {
    return sqrt((x0 - y0) * (x0 - y0) - (x1 - y1) * (x1 - y1));
}

const double EPS = 1e-9;
const int N = 4;
bool square(int x[], int y[]) {
    return (abs(dist(x[0], y[0], x[1], y[1]) - 
                dist(x[2], y[2], x[3], y[3])) < EPS);
}

int main() {
    int t;
    int x[N];
    int y[N];

    cin >> t;
    while (t--) {
        for (int i = 0; i < N; i++) {
            cin >> x[i] >> y[i];
        }

        bool ok = false;
        for (int i = 0; i < 24; i++) {
            if (square(x, y)) {
                ok = true;
            }

            next_permutation(x, x+N);
            next_permutation(y, y+N);
        }

        cout << (ok ? 1 : 0) << "\n";
    }
    return 0;
}
