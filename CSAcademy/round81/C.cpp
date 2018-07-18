#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int64_t fat[N];
void compute_fat(int n, int mod) {
    assert(n < N);
    fat[0] = 1;
    for (int i = 1; i <= n; i++) {
        fat[i] = (fat[i-1] * i) % mod;
    }
}

int main() {
    const int mod = 1000 * 1000 * 1000 + 7;
    int n, arr[N], q0 = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 0)
            q0++;
    }

    compute_fat(n, mod);

    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        int64_t pot = 1;
        for (int k = 0; k < n-1; k++) {
            cout << arr[i] << " x " << pot << " x " << fat[n-1] << endl;
            ans = (ans + arr[i] * pot * (fat[n-1] - q0)) % mod;

            pot = (pot * 10) % mod;
        }

        if (arr[i] != 0)
            ans = (ans + arr[i] * pot * fat[n-1]) % mod;
    }

    cout << ans << endl;
    return 0;
}

