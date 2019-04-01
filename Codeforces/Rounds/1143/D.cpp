// Codeforces - The Beatles - 1143D Div2
#include <bits/stdc++.h>
using namespace std;

const int64_t inf = 1e18;
int64_t n, k;

int64_t calc(int64_t a, int64_t b, int64_t z) {
    int64_t c = (a + b + k) % k;
    int64_t l = k * z + c;
    return n * k / __gcd(n * k, l);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t a, b;

    cin >> n >> k;
    cin >> a >> b;

    int64_t x = inf, y = 0;

    for (int z = 0; z < n; z++) {
        x = min({x, calc(a, b, z), calc(-a, b, z), calc(a, -b, z), calc(-a, -b, z)});
        y = max({y, calc(a, b, z), calc(-a, b, z), calc(a, -b, z), calc(-a, -b, z)});
    }

    cout << x << " " << y << "\n";

    return 0;
}
