// Codeforces - Powers of Two - 1095C Div3
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int B = 31;
    int n, k;

    cin >> n >> k;

    multiset<int, greater<>> ss;

    for (int i = 0; i < B; i++) {
        if (n & (1 << i)) {
            ss.insert(1 << i);
        }
    }

    if ((int) ss.size() > k) {
        cout << "NO\n";
        return 0;
    }

    while ((int) ss.size() < k) {
        int p = *ss.begin();
        if (p == 1) {
            cout << "NO\n";
            return 0;
        }

        ss.erase(ss.begin());
        ss.insert(p/2);
        ss.insert(p/2);
    }

    cout << "YES\n";
    for (const auto &x : ss) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
