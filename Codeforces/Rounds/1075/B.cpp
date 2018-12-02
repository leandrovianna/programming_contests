#include <bits/stdc++.h>
using namespace std;

const int N = 3 * 100 * 1000 + 10;
int a[N], t[N];
int64_t x[N];
int pref[N], suff[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n+m; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n+m; i++) {
        cin >> t[i];
    }

    pref[0] = (t[0] == 1 ? 0 : -1);
    for (int i = 1; i < n+m; i++) {
        if (t[i] == 1)
            pref[i] = i;
        else
            pref[i] = pref[i-1];
    }

    suff[n+m-1] = (t[n+m-1] == 1 ? n+m-1 : -1);
    for (int i = n+m-2; i >= 0; i--) {
        if (t[i] == 1)
            suff[i] = i;
        else
            suff[i] = suff[i+1];
    }

    for (int i = 0; i < n+m; i++) {
        if (t[i] == 1)
            continue;

        int64_t x1 = (pref[i] != -1 ? x[pref[i]] : -2e9);
        int64_t x2 = (suff[i] != -1 ? x[suff[i]] : 2e9);

        if (x[i] - x1 <= x2 - x[i])
            a[pref[i]]++;
        else
            a[suff[i]]++;
    }

    for (int i = 0; i < n+m; i++) {
        if (t[i] == 1)
            cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}
