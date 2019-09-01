// Kattis - Covered Walkway
#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;
const double eps = 1e-9;

struct Sol {
    int64_t x, prevCost;
} dq[N];

int64_t getcost(Sol s, int64_t x) {
    int64_t d = s.x - x;
    return d * d + s.prevCost;
}

// Time that solution a overtakes solution b
double timeovertaken(Sol a, Sol b) {
     return 
         (b.prevCost - a.prevCost + b.x * b.x - a.x * a.x) / 
         (2.0 * (a.x - b.x));
}

int cmp(double x, double y) {
    // x == y
    if (fabs(x - y) < eps)
        return 0;
    else if (x < y)
        return -1;
    else
        return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int64_t c, best = 0, x;

    int fptr = 0, bptr = 0;

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> x;

        Sol part = {x, best+c};

        while (bptr - fptr >= 2 && 
                cmp(timeovertaken(dq[bptr-1], dq[bptr-2]), timeovertaken(part, dq[bptr-2])) <= 0) {
            bptr--;
        }
        dq[bptr++] = part;

        while (fptr + 1 < bptr && getcost(dq[fptr], x) >= getcost(dq[fptr+1], x)) {
            fptr++;
        }

        best = getcost(dq[fptr], x);
    }

    cout << best << "\n";
    return 0;
}
