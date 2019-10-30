// Live Archive - Modified LCS - 6763
#include <bits/stdc++.h>
using namespace std;

int64_t lcm(int64_t a, int64_t b) {
    return a * (b / __gcd(a, b));
}

int64_t extended_euclids(int64_t a, int64_t b, int64_t &x, int64_t &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    } else {
        int64_t x1, y1;
        int64_t c = extended_euclids(b % a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return c;
    }
}

pair<int64_t, int64_t> extendedEuclids(int64_t a, int64_t b) {
    if (b == 0) {
        return {1, 0};
    } else {
        auto p = extendedEuclids(b, a % b);
        return {p.second,
            p.first - floor((double)a / b) * p.second};
    }
}

int64_t ceil(int64_t x, int64_t y) {
    return x / y + (x % y > 0 ? 1 : 0);
}

int main() {
    int t;
    int64_t f1, d1, f2, d2, n1, n2;

    cin >> t;

    while (t--) {
        cin >> n1 >> f1 >> d1
            >> n2 >> f2 >> d2;

        if (f2 < f1) {
            swap(f2, f1);
            swap(d2, d1);
            swap(n2, n1);
        }

        if (f2 - f1 >= 10000) {
            f1 += ((f2 - f1) / d1) * d1;
        }

        assert(f2 >= f1);

        // f1 + m1 * d1 == f2 + m2 * d2
        // m1 * d1 - m2 * d2 == f2 - f1

        int64_t m1 = 0, m2 = 0, k;
        //int64_t g = extended_euclids(d1, d2, m1, m2);
        int64_t g = __gcd(d1, d2);

        if ((f2 - f1) % g != 0) {
            cout << "0\n";
            continue;
        }

        tie(m1, m2) = extendedEuclids(d1, d2);

        m1 *= (f2 - f1) / g;
        m2 *= (f2 - f1) / g;
        m2 *= -1;

        k = 0;
        if (m1 < 0) {
            k = ceil(abs(m1), d2 / g);
        }
        
        m1 += k * (d2 / g);
        m2 -= k * (-d1 / g);

        k = 0;
        if (m2 < 0) {
            k = ceil(abs(m2), d1 / g);
        }

        m1 += k * (d2 / g);
        m2 -= k * (-d1 / g);

        assert(m1 >= 0 && m2 >= 0);

        int64_t g1 = lcm(d1, d2) / d1, g2 = lcm(d1, d2) / d2;

        //int64_t ans = min((n1 - m1 + g1 - 1) / g1, (n2 - m2 + g2 - 1) / g2);
        int64_t ans = min(ceil(n1 - m1, g1), ceil(n2 - m2, g2));

        if (m1 >= n1 || m2 >= n2) {
            ans = 0;
        }

        cout << ans << "\n";
    }
    return 0;
}
