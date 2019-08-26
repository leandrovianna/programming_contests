// Codeforces - Average Superhero Gang Power - 1111B Div2
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int64_t a[N], pf[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n, k, m;

    cin >> n >> k >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n, greater<>());

    for (int i = 0; i < n; i++) {
        pf[i] = a[i] + (i > 0 ? pf[i-1] : 0);
    }

    double ans = 0;

    for (int i = 0; i < n; i++) {
        if (m < n - i - 1)
            continue;

        double avg = pf[i] + min((i+1) * k, m - n + i + 1);
        avg /= i+1;
        ans = max(ans, avg);
    }

    cout << fixed << setprecision(10);
    cout << ans << "\n";

    return 0;
}
