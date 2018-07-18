// Codeforces - Modified GCD - 75C Div2
#include <bits/stdc++.h>
using namespace std;

vector<int> div(int n) {
    vector<int> d;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (n/i != i) {
                d.push_back(n/i);
            }
        }
    }
    sort(d.begin(), d.end());
    return d;
}

int main() {
    int a, b, n, low, high;

    vector<int> d1, d2;

    cin >> a >> b >> n;

    d1 = div(a);
    d2 = div(b);

    set<int> divs;

    for (const auto &x : d1) {
        for (const auto &y : d2) {
            if (x == y) {
                divs.insert(x);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> low >> high;

        auto it = divs.upper_bound(high);

        if (it != divs.begin() && *prev(it) >= low) {
            cout << *prev(it) << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
