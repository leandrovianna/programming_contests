// Codeforces - Divisors of Two integers - 1108C
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    multiset<int> ss;

    int mx1 = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        mx1 = max(x, mx1);
        ss.insert(x);
    }

    for (int i = 1; i * i <= mx1; i++) {
        if (mx1 % i == 0) {
            auto it = ss.find(i);
            assert(it != ss.end());

            ss.erase(it);

            if (mx1 / i != i) {
                it = ss.find(mx1 / i);
                assert(it != ss.end());
                ss.erase(it);
            }
        }
    }

    int mx2 = *prev(ss.end());

    cout << mx1 << " " << mx2 << "\n";

    return 0;
}
