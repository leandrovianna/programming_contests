// TAP 2018/2 - Mount Marathon - M8
// URI - 2915
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 60;
    int n;
    int a[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;

    for (int i = 1; i < n; i++) {
        if (a[i-1] < a[i]) {
            ans++;
        }
    }

    cout << ans+1 << endl;
    return 0;
}
