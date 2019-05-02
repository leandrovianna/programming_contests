// UVA - Army buddies - 12356
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int N = 100 * 1000 + 10;
    pair<int, int> a[N];
    int s, b, l, r;

    auto print = [&](int l, int r) {
        (a[l].first == 0 ? cout << "*" : cout << a[l].first);
        cout << " ";
        (a[r].second == s+1 ? cout << "*" : cout << a[r].second);
        cout << "\n";
    };

    while (cin >> s >> b, s || b) {
        a[0] = {-1, 1};
        a[s+1] = {s, -1};
        for (int i = 1; i <= s; i++) {
            a[i] = {i-1, i+1};
        }

        for (int i = 0; i < b; i++) {
            cin >> l >> r;

            print(l, r);

            a[a[l].first].second = a[r].second;
            a[a[r].second].first = a[l].first;
        }
        cout << "-" << "\n";
    }
    return 0;
}
