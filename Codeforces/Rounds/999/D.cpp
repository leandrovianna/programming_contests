// Codeforces - Equalize the Remainders - 999D Div3
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 2 * 100 * 1000 + 10;
    int64_t n, m, a[N];
    
    cin >> n >> m;

    int64_t target = n / m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int64_t, int> cnt;
    set<pair<int64_t, int> > nums;

    for (int i = 0; i < n; i++) {
        cnt[a[i] % m]++;
        if (cnt[a[i] % m] > target) {
            nums.insert({a[i] % m, i});
        }
    }

    int64_t ans = 0;
    for (int pass = 0; pass < 2; pass++) {
        for (int mi = 0; mi < m; mi++) {
            while (cnt[mi] < target) {
                auto it = nums.begin(); 
                int64_t inc;
                if (mi > it->first) {
                    inc = mi - it->first;
                } else {
                    inc = (m + mi) - it->first;
                }

                ans += inc;
                a[it->second] += inc;
                cnt[it->first]--;
                cnt[mi]++;
                nums.erase(it);
            }
        }
    }

    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
