// Codeforces - Nested Segments - 976C
#include <bits/stdc++.h>
using namespace std;

const int N = 300100;
struct Seg {
    int l, r, i;
} segs[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0, l, r; i < n; i++) {
        cin >> l >> r;
        segs[i] = {l, r, i+1};
    }

    sort(segs, segs+n, [](const auto &a, const auto &b) {
            return a.l < b.l || (a.l == b.l && a.r > b.r);
        });

    multiset<int> points;
    int found = -1;
    for (int i = 0; i < n; i++) {
        points.erase(points.begin(), points.lower_bound(segs[i].l));

        auto it = points.lower_bound(segs[i].r);
        if (it != points.end()) {
            found = i;
            break;
        } else {
            points.insert(segs[i].r);
        }
    }

    if (found == -1) {
        cout << "-1 -1\n";
    } else {
        for (int i = 0; i < n; i++) {
            if (found == i) continue;

            if (segs[i].l <= segs[found].l 
                    && segs[found].r <= segs[i].r) {
                cout << segs[found].i << " " << segs[i].i << "\n";
                break;
            }
        }
    }

    return 0;
}
