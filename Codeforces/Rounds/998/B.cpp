// Codeforces - Cutting - 998B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 110;
    int n, b, a[N];

    cin >> n >> b;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int even = 0, odd = 0;
    vector<int> costs;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            even++;
        else
            odd++;

        if (i < n-1 && even == odd) {
            costs.push_back(abs(a[i] - a[i+1]));
        }
    }

    int m = 0;
    int ans = 0;

    sort(costs.begin(), costs.end());

    for (const auto &cost : costs) {
        if (m + cost <= b) {
            m += cost;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
