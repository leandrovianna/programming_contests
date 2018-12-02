#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    int64_t d;
    const int64_t factor = 1000000000;
    const double EPS = 1e-6;

    cin >> t;

    cout << fixed << setprecision(10);

    while (t--) {
        cin >> d;
        if (d == 0) {
            cout << "Y 0 0\n";
            continue;
        }

        bool found = false;

        d *= factor;
        int64_t low = 0, high = d, mid;

        while (low <= high) {
            mid = (low + high) / 2;
            double v = ((double) mid / factor) * ((double) (d - mid) / factor);

            if (fabs(v - ((double) d / factor)) < EPS) {
                found = true;
                cout << "Y " << (d - mid) / (double) factor 
                    << " " << (double) mid / factor << "\n";
                break;
            } else if (v > (double) d / factor) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        if (!found)
            cout << "N\n";
    }
    return 0;
}
