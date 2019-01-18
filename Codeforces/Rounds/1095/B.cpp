// Codeforces - Array Stabilization - 1095B Div3
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    cout << min(a[n-2] - a[0], a[n-1] - a[1]) << "\n";

    return 0;
}
