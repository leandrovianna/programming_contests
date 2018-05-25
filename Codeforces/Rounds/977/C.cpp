#include <bits/stdc++.h>
using namespace std;

map<int64_t, int> cnt;
map<int64_t, int> acc;

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    int64_t y;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> y;
        cnt[y]++;
    }

    int64_t prev = 0;
    for (const auto &p : cnt) {
        acc[p.first] += acc[prev] + p.second;
        prev = p.first;
    }

    acc.erase(0);

    if (k == 0 && cnt[1] == 0) {
        cout << 1 << endl;
        return 0;
    }

    int64_t x = -1;
    for (const auto &p : acc) {
        if (p.second == k) {
            x = p.first;
            break;
        }

        if (p.second > k)
            break;
    }

    cout << x << endl;

    return 0;
}
