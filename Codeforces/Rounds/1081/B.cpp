// Codeforces - Farewell Party - 1081B
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int ans[N];
vector<int> bucket[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        bucket[n - x].push_back(i);
    }

    int type = 0;
    for (int x = 1; x <= n; x++) {
        if (bucket[x].size() % x == 0) {
            for (size_t i = 0; i < bucket[x].size(); i++) {
                if (i % x == 0) {
                    type++;
                }
                ans[bucket[x][i]] = type;
            }
        } else {
            cout << "Impossible\n";
            return 0;
        }
    }

    if (type > n) {
        cout << "Impossible\n";
        return 0;
    } else {
        cout << "Possible\n";
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
