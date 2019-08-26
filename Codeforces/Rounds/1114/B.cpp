// Codeforces - Yet Another Array Partitioning Task - 1114B Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int64_t a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;

    cin >> n >> m >> k;

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pq.push({a[i], i});
    }

    vector<int> p, bigger;
    int64_t sum = 0;

    for (int i = 0; i < k * m; i++) {
        int j = pq.top().second;
        pq.pop();

        sum += a[j];
        bigger.push_back(j);
    }

    sort(bigger.begin(), bigger.end());

    for (int i = 0; i < k * m - 1; i++) {
        if (i % m == m - 1) {
            p.push_back(bigger[i] + 1);
        }
    }

    cout << sum << "\n";
    for (const auto &idx : p) {
        cout << idx << " ";
    }
    cout << "\n";

    return 0;
}
