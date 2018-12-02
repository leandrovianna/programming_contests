// Codeforces - Benches - 1042A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 110;
    int n, m, a[N], mx = 0;

    cin >> n >> m;

    multiset<int> ss;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        ss.insert(a[i]);
    }

    int k = m;
    while (k > 0) {
        auto it = ss.begin();
        ss.insert(*it+1);
        ss.erase(it);
        k--;
    }

    cout << *prev(ss.end()) << " " << mx + m << endl;

    return 0;
}
