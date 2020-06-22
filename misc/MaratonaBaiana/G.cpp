#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> lot;

    for (int i = 0, x; i < 6; i++) {
        cin >> x;
        lot.insert(x);
    }

    int n; 
    cin >> n;

    int v6 = 0, v5 = 0, v4 = 0;

    for (int i = 0, m, x; i < n; i++) {
        cin >> m;
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            cin >> x;
            if (lot.find(x) != lot.end()) {
                cnt++;
            }
        }

        if (cnt == 6) {
            v6++;
        } else if (cnt == 5) {
            v5++;
        } else if (cnt == 4) {
            v4++;
        }
    }

    cout << v6 << " " << v5 << " " << v4 << "\n";
    return 0;
}
