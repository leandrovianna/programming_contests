// Codeforces - Array and Segments (Easy Version) - 1108E1
#include <bits/stdc++.h>
using namespace std;

const int M = 310, N = 310, inf = 100000000;
pair<int, int> seg[M];
int a[N], b[N];
vector<int> indexes;

int test(int exclude, int n, int m) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }

    indexes.clear();
    for (int i = 0; i < m; i++) {
        if (exclude < seg[i].first || seg[i].second < exclude) {
            indexes.push_back(i);
            for (int j = seg[i].first; j <= seg[i].second; j++) {
                b[j]--;
            }
        }
    }

    int mx = -inf;
    for (int i = 0; i < n; i++) {
        mx = max(mx, b[i]);
    }

    int mi = mx;
    for (int i = 0; i < n; i++) {
        mi = min(mi, b[i]);
    }

    return mx - mi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> seg[i].first >> seg[i].second;
        seg[i].first--;
        seg[i].second--;
    }

    int d = test(0, n, m), besti = 0;

    for (int i = 1; i < n; i++) {
        int e = test(i, n, m);
        if (e > d) {
            d = e;
            besti = i;
        }
    }
    
    test(besti, n, m);

    cout << d << "\n";
    cout << indexes.size() << "\n";
    for (const auto &idx : indexes) {
        cout << idx+1 << " ";
    }
    cout << "\n";

    return 0;
}
