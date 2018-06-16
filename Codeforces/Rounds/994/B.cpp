// Codeforces - Knights of a Polygonal Table - 994B Div2
#include <bits/stdc++.h>
using namespace std;

struct info {
    int64_t p, c, i;
    bool operator<(const info &other) {
        return this->p < other.p
            || (this->p == other.p && this->i < other.i);
    }
};

const int N = 100 * 1000 + 10;
int n, k;
info a[N];
int64_t ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i].p;
        a[i].i = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i].c;
    }

    sort(a, a+n);  
    vector<int64_t> greaters;

    for (int i = 0; i < n; i++) {
        int64_t sum = 0;
        for (const auto &x : greaters)
            sum += x;

        int ans_idx = a[i].i;
        ans[ans_idx] = sum + a[i].c;

        size_t p = 0;
        for (; p < greaters.size(); p++) {
            if (greaters[p] >= a[i].c)
                break;
        }
        greaters.insert(greaters.begin() + p, a[i].c);

        if ((int) greaters.size() > k) {
            greaters.erase(greaters.begin());
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
