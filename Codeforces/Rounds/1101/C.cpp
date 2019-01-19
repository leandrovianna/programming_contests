// Codeforces - Division and Union - 1101C - Edu Round 58
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
pair<pair<int, int>, int> a[N];
int answer[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n;

    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first.first >> a[i].first.second;
            a[i].second = i;
        }

        sort(a, a+n);

        answer[a[0].second] = 0;
        bool ok = false;

        for (int i = 1; i < n; i++) {
            if (a[i].first.first <= a[i-1].first.second) {
                answer[a[i].second] = answer[a[i-1].second];
                a[i].first.first = a[i-1].first.first;
                a[i].first.second = max(a[i].first.second, a[i-1].first.second);
            } else {
                answer[a[i].second] = (answer[a[i-1].second] + 1) & 1;
                ok = true;
            }
        }

        if (!ok) {
            cout << "-1\n";
        } else {
            for (int i = 0; i < n; i++) {
                cout << answer[i] + 1 << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
