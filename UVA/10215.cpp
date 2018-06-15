// UVA - The Largest/Smallest Box... - 10215
#include <bits/stdc++.h>
using namespace std;

int main() {
    double w, l, mx, my;
    const double eps = 1e-9;

    cout << fixed << setprecision(3);

    while (cin >> w >> l) {
        mx = w + l - sqrt(l * l - l * w + w * w);
        mx /= 6.0;
        my = min(w / 2, l / 2) + eps;

        cout << mx << " 0.000 " << my << "\n";
    }
    return 0;
}
