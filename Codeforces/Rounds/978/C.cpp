// Codeforces - Letters - 978C
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int64_t a[N], x;
int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k = 0;
    int64_t sum = a[0];
    for (int i = 0; i < m; i++) {
        cin >> x;

        while (sum < x && k < n) {
            k++;
            sum += a[k];
        }

        cout << k+1 << " " << a[k] + x - sum << "\n";
    }

    return 0;
}
