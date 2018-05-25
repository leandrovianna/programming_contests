#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int64_t a[N];
map<int64_t, vector<int> > cnt;

int dp[N];

int search(int i) {
    if (dp[i] != -1)
        return dp[i];

    int j = i;
    for (const auto &p : cnt[a[i]+1]) {
        if (p > i) {
            j = p;
            break;
        }
    }

    if (j != i) {
        return dp[i] = 1 + search(j);
    }

    return dp[i] = 1;
}

void print(int i) {
    cout << i+1;

    int j = i;
    for (const auto &p : cnt[a[i]+1]) {
        if (p > i) {
            j = p;
            break;
        }
    }

    if (j != i) {
        cout << " ";
        print(j);
        return;
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int n, x;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]].push_back(i);
    }

    memset(dp, -1, sizeof(dp));
    int ans = 0;
    int maxj = 0;
    for (int i = 0; i < n; i++) {
        x = search(i);
        if (ans < x) {
            ans = x;
            maxj = i;
        }
    }

    cout << ans << endl;
    print(maxj);

    return 0;
}
