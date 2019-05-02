// UVA - 10038 - Jolly Jumpers
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 3010;
    int a[N], cnt[N];
    int n;

    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i < n; i++) {
            int v = abs(a[i] - a[i-1]);
            if (v < N)
                cnt[v]++;
        }

        bool ans = true;
        for (int i = 1; i <= n-1; i++) {
            if (cnt[i] != 1) {
                ans = false;
                break;
            }
        }

        cout << (ans ? "Jolly" : "Not jolly") << "\n";
    }
    return 0;
}
