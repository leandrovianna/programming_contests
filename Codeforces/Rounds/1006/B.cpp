#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    const int N = 2010;
    int n, k;
    int64_t a[N];
    set<pair<int64_t, int> > ss;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ss.insert({a[i], i});
    }

    int j = 0;
    int64_t sum = 0;
    vector<int> pos;
    for (auto it = ss.rbegin(); it != ss.rend() && j < k; it++) {
        sum += it->first;
        pos.push_back(it->second + 1);
        j++;
    }

    sort(pos.begin(), pos.end());

    j = 0;
    for (size_t i = 0; i < pos.size(); i++) {
        pos[i] = pos[i] - j;
        j += pos[i];
    }

    if (j < n) {
        pos[pos.size() - 1] += n - j;
    }

    cout << sum << "\n";
    for (const auto &p : pos) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}
