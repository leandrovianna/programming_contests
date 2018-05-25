#include <bits/stdc++.h>
using namespace std;

const int N = 510;
int n, a[N][N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int dj = (j + i) % n;
            assert(0 <= dj && dj < n);
            sum += a[i][dj];
        }

        ans = max(ans, sum);
    }

    cout << ans << endl;
    return 0;
}
