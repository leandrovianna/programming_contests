#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 10;
int64_t a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    set<int> ss;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        ss.insert(a[i]);
    }
    
    ss.erase(0);

    cout << ss.size() << "\n";
    return 0;

    int64_t acc = 0, ans1 = 0, ans2 = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;

        a[i] += acc;

        if (a[i] != 0) {
            acc += -a[i];
            ans1++;
        }
    }

    acc = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) continue;

        b[i] += acc;

        if (b[i] != 0) {
            acc += -b[i];
            ans2++;
        }
    }

    cout << min(ans1, ans2) << "\n";
    return 0;
}
