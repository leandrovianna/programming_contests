// UVA - Solve It - 10341
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

int main() {
    int p, q, r, s, t, u;
    double lo, hi, x;

    auto f = [&](double x) {
        return p * exp(-x) + q * sin(x) + r * cos(x)
            + s * tan(x) + t * x * x + u;
    };

    cout << fixed << setprecision(4);

    while (cin >> p >> q >> r >> s >> t >> u) {
        if (f(0) * f(1) > 0) {
            cout << "No solution" << endl;
        } else {
            lo = 0;
            hi = 1;

            while (lo + EPS < hi) {
                x = (lo + hi) / 2.0;

                if (f(x) * f(lo) <= 0) {
                    hi = x;
                } else {
                    lo = x;
                }
            }

            cout << (lo+hi)/2 << endl;
        }
    }
    return 0;
}
