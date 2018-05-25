// Live Archive ICPC - Rent your airplane and make money - 2942
#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int n;
typedef struct {
    int st, d;
    int64_t p;
} order;

bool operator< (const order x, const order y) {
    return x.st < y.st || (x.st == y.st && x.d < y.d);
}

order ord[N];

int64_t dp[N];
int used[N], vis = 1;

int64_t solve(int i) {
    if (i == n) {
        return 0;
    }

    if (used[i] == vis)
        return dp[i];

    int64_t &ans = dp[i];

    ans = solve(i+1);

    auto it = lower_bound(ord+i, ord+n, 
            order{ord[i].st + ord[i].d, -1, -1});

    if (it != ord+n) {
        for (int j = it - ord; j < n; j++) {
            ans = max(ans, ord[i].p + solve(j));
        }
    } else {
        ans = max(ans, ord[i].p);
    }

    used[i] = vis;
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    string id;
    vector<int64_t> ans;

    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> id;
            cin >> ord[i].st >> ord[i].d >> ord[i].p;
        }
        sort(ord, ord+n);
        ans.push_back(solve(0));
        vis++;
    }

    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
        if (i+1 != ans.size())
            cout << "\n";
    }

    return 0;
}
