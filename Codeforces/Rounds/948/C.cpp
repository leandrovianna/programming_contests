//Codeforces - Producing Snow - 948C Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    const int N = 100100;
    int n;
    int v[N];
    int t[N];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
        cin >> t[i];

    multiset<int64_t> ms;

    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
        int64_t ans = 0;
        ms.insert(v[i] + sum);
        while (ms.size() && (*ms.begin() - sum) < t[i]) {
            ans += *ms.begin() - sum;
            ms.erase(ms.begin());
        }
        ans += ms.size() * t[i];
        sum += t[i];
        cout << ans;
        if (i < n-1)
            cout << " ";
    }
    cout << endl;

    return 0;
}
