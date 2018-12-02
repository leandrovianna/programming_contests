#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    map<int, int> cnt;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }

    vector<int> qtd;
    for (const auto &p : cnt) {
        qtd.push_back(p.second);
    }

    sort(qtd.begin(), qtd.end());

    int64_t ans = 0, l_ans;
    int p, idx;
    for (int i = 0, sz = qtd.size(); i < sz; i++) {
        for (int q = 1; q <= qtd[i]; q++) {
            l_ans = q;
            p = q * 2;
            idx = i+1;

            while (idx < sz) {
                idx = lower_bound(qtd.begin()+idx, qtd.end(), p) - qtd.begin();

                if (idx == sz)
                    break;

                l_ans += p;
                p = p * 2;
                idx++;
            }

            ans = max(ans, l_ans);
        }
    }

    cout << ans << endl;
    return 0;
}
