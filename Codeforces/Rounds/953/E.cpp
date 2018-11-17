#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100 * 1000 + 10;
int n, a[N], x, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    k = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[k++] = x;

        while (k > 1 && a[k-2] == a[k-1]) {
            a[k-2]++;
            k--;
        }
    }

    cout << k << "\n";
    for (int i = 0; i < k; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}
