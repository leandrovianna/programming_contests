//Codeforces - Petya and Countryside - 66B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    const int N = 1010;
    int n, h[N], ans;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];

    int left[N], right[N];

    // precalcular left
    left[0] = 0;
    for (int i = 1; i < n; i++) {
        if (h[i] >= h[i-1])
            left[i] = left[i-1] + 1;
        else
            left[i] = 0;
    }

    // precalcular right
    right[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        if (h[i] >= h[i+1])
            right[i] = right[i+1] + 1;
        else
            right[i] = 0;
    }

    ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, left[i] + right[i] + 1);
    }

    cout << ans << endl;
    return 0;
}
