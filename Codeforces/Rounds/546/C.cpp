// Codeforces - Soldier and Cards - 546C
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k1, k2;
    deque<int> d1, d2;

    cin >> n;
    cin >> k1;
    for (int i = 0, x; i < k1; i++) {
        cin >> x;
        d1.push_back(x);
    }

    cin >> k2;
    for (int i = 0, x; i < k2; i++) {
        cin >> x;
        d2.push_back(x);
    }

    for (int i = 0; i < 1000; i++) {
        if (d1.empty()) {
            cout << i << " 2\n";
            return 0;
        } else if (d2.empty()) {
            cout << i << " 1\n";
            return 0;
        }

        int x1 = d1.front();
        int x2 = d2.front();
        d1.pop_front();
        d2.pop_front();

        if (x1 > x2) {
            d1.push_back(x2);
            d1.push_back(x1);
        } else {
            d2.push_back(x1);
            d2.push_back(x2);
        }
    }

    cout << "-1\n";

    return 0;
}
