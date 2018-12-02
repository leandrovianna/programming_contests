#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100 * 1000 + 10;
int64_t a[N], sum;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    multiset<int64_t> values;
    sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        values.insert(a[i]);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        sum -= a[i];
        auto it = values.find(a[i]);
        if (it != values.end())
            values.erase(it);

        if (sum % 2 == 0 && values.count(sum/2) > 0) {
            ans.push_back(i);
        }

        sum += a[i];
        values.insert(a[i]);
    }

    cout << ans.size() << "\n";
    for (const auto &x : ans) {
        cout << x+1 << " ";
    }
    cout << "\n";
    return 0;
}
