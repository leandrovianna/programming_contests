#include <bits/stdc++.h>
using namespace std;

int64_t exp(int64_t b, int64_t e, int64_t mod) {
    int64_t ans = 1;
    while (e) {
        if (e & 1) {
            ans = (b * ans) % mod;
        }

        b = (b * b) % mod;
        e >>= 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    int m;
    cin >> m;
    int64_t x;
    vector<int64_t> ans;
    for (int i = 0; i < m; i++) {
        cin >> x;

        int64_t sum = 0;
        for (int j = 0, k = n.size()-1, sz = n.size(); j < sz; 
                j++, k--) {
            if (n[j] == '1') {
                sum = (sum + exp(2, k, x)) % x;
            }
        }

        if (sum == 0) {
            ans.push_back(x);
        }
    }

    if (ans.size() == 0) {
        cout << "Nenhum";
    } else {
        sort(ans.begin(), ans.end());
        for (size_t i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i < ans.size()-1) {
                cout << " ";
            }
        }
    }
    cout << "\n";
    return 0;
}
