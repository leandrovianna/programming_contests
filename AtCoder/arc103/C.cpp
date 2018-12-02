// AtCoder - Regular Contest 103 - C /\/\/\/
#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 10;
int n;
map<int, int> cnt1, cnt2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (i % 2)
            cnt1[x]++;
        else
            cnt2[x]++;
    }

    int most1 = 0, app1 = 0, most2 = 0, app2 = 0;
    int app12 = 0, app22 = 0;

    for (int i = 1; i < N; i++) {
        if (app1 < cnt1[i]) {
            app12 = app1;
            most1 = i;
            app1 = cnt1[i];
        } else if (app12 < cnt1[i]) {
            app12 = cnt1[i];
        }

        if (app2 < cnt2[i]) {
            app22 = app2;
            most2 = i;
            app2 = cnt2[i];
        } else if (app22 < cnt2[i]) {
            app22 = cnt2[i];
        }
    }

    int ans = 0;
    if (most1 == most2) {
        ans = min( (n/2 - app1) + (n/2 - app22),
                (n/2 - app12) + (n/2 - app2));
    } else {
        ans = (n/2 - app1) + (n/2 - app2);
    }

    cout << ans << endl;
    return 0;
}
