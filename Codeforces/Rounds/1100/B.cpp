// Codeforces - Build a Contest - 1100B
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    multiset<int> mt;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        mt.insert(0);
    }

    for (int i = 0, x; i < m; i++) {
        cin >> x;
        
        auto it = mt.find(cnt[x]);
        if (it != mt.end())
            mt.erase(it);

        cnt[x]++;
        mt.insert(cnt[x]);

        int mx = *mt.begin();
        if (ans < mx) {
            ans++;
            cout << "1";
        } else {
            cout << "0";
        }
    }

    cout << endl;
    return 0;
}
