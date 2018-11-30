// Codeforces - Increasing Frequency - 1082E Edu Round
#include <bits/stdc++.h>
using namespace std;

const int N = 500100;
int a[N], cnt[N], r[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, c, qtc = 0;
    
    cin >> n >> c;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == c)
            qtc++;
        else
        {
            cnt[a[i]] = max(qtc, cnt[a[i]]);
            cnt[a[i]]++;
            ans = max(ans, cnt[a[i]] - qtc);
        }
    }
    cout << qtc + ans << endl;

    return 0;
}
