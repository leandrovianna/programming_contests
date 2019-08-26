// Codeforces - Minimum Array - 1157E Div 3
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int a[N];
multiset<int> b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        b.insert(x);
    }

    for (int i = 0; i < n; i++) {
        auto it = b.lower_bound(n - a[i]);

        if (it == b.end()) {
            it = b.begin();
        }

        int x = (a[i] + *it) % n;
        b.erase(it);

        cout << x << " ";
    }

    cout << "\n";

    return 0;
}
