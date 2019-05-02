//UVA - Back to Intermediate Math - 10773
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    double d, u, v;

    cout << fixed << setprecision(3);

    cin >> t;
    for (int ti = 1; ti <= t; ti++) {
        cin >> d >> v >> u;

        cout << "Case " << ti << ": ";

        double x = d / u;

        if (u == 0 || v == 0 || u <= v)
            cout << "can't determine" << "\n";
        else {
            double y = d / sqrt(u*u - v*v);
            cout << abs(x - y) << "\n";
        }
    }
    return 0;
}
