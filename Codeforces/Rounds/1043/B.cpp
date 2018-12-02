#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, a[N], d[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    d[0] = a[0];
    for (int i = 1; i < n; i++) {
        d[i] = a[i] - a[i-1];
    }

    set<int> ans = {n};
    for (int l = 1; l < n; l++) {
        ans.insert(l);
        for (int i = l; i < n; i++) {
            if (d[i] != d[i-l]) {
                ans.erase(l);
                break;
            }
        }
    }

    cout << ans.size() << "\n";
    for (const auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
