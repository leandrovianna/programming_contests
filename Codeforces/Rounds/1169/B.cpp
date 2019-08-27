// Codeforces - Pairs - 1169B Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 300100;
pair<int, int> a[N];
int cnt[N];

bool test(int fixed, int m, int n) {
    memset(cnt, 0, sizeof(cnt));

    int total = 0;
    for (int i = 0; i < m; i++) {
        if (a[i].first == fixed || a[i].second == fixed)
            continue;

        total++;
        cnt[a[i].first]++;
        cnt[a[i].second]++;
    }

    for (int v = 1; v <= n; v++) {
        if (cnt[v] == total) {
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }

    if (test(a[0].first, m, n) || test(a[0].second, m, n)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
