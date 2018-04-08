//Codejam - Trouble Sort - 2018 Qualification
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 100100;
    int t, n, a[N], b[N], c[N];
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    for (int ti = 1; ti <= t; ti++) {
        cin >> n;
        int k = 0, l = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2)
                cin >> b[l++];
            else
                cin >> a[k++];
        }

        sort(a, a+k);
        sort(b, b+l);

        for (int i = 0; i < n; i++) {
            if (i % 2)
                c[i] = b[i/2];
            else
                c[i] = a[i/2];
        }

        int idx = -1;
        for (int i = 1; i < n; i++) {
            if (c[i-1] > c[i]) {
                idx = i-1;
                break;
            }
        }

        cout << "Case #" << ti << ": " << 
            (idx == -1 ? "OK" : to_string(idx)) << "\n";
    }
    return 0;
}
