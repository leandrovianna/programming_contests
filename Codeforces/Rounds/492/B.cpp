//Codeforces - Vanya and Lanterns - 492B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    const int N = 1010;
    int point[N];
    int n, l;

    cin >> n >> l;

    for (int i = 0; i < n; i++)
        cin >> point[i];

    sort(point, point+n);

    // distance from begin to first point
    double ans = point[0];

    for (int i = 1; i < n; i++) {
        // distance between points divide by 2
        ans = max(ans, (point[i] - point[i-1]) / 2.0);
    }

    // distance from last point to end
    ans = max(ans, (double) l - point[n-1]);

    cout << fixed << ans << endl;

    return 0;
}
