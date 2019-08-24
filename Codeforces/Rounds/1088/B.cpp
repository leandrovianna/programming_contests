// Codeforces - Ehab and subtraction - 1088B
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;

    cin >> n >> k;

    set<int> ms;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        ms.insert(x);
    }

    int acc = 0;
    for (int ti = 0; ti < k; ti++) {
        auto it = ms.begin();
        if (it == ms.end()) {
            cout << "0\n";
            continue;
        }

        int v = *it - acc;
        cout << v << "\n";
        acc += v;
        ms.erase(it);
    }
    return 0;
}
