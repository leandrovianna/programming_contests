// UVA - Trainsorting - 11456
#include <bits/stdc++.h>
using namespace std;

namespace LIS {
    const int N = 2020;
    int f[N]; // lis(i)

    int lis(int a[], const int n) {
        int ans = 1;
        for (int i = n-1; i >= 0; i--) {
            f[i] = 1;
            for (int j = n-1; j > i; j--) {
                if (a[i] < a[j]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
            
            ans = max(ans, f[i]);
        }
        return ans;
    }
}

namespace LDS {
    const int N = 2020;
    int f[N]; // lds(i)

    int lds(int a[], const int n) {
        int ans = 1;
        for (int i = n-1; i >= 0; i--) {
            f[i] = 1;
            for (int j = n-1; j > i; j--) {
                if (a[i] > a[j]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
            
            ans = max(ans, f[i]);
        }
        return ans;
    }
}

int main() {
    const int N = 4020;
    int t, n, a[N];

    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        LIS::lis(a, n);
        LDS::lds(a, n);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, LIS::f[i] + LDS::f[i] - 1);
        }

        cout << ans << endl;
    }
}
