// Codeforces - Tree Reconstruction - 1041D Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 1010;
    int n, a[N], b[N];

    bool ans = true;

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a[i] >> b[i];
        if (a[i] == n)
            swap(a[i], b[i]);

        if (b[i] != n)
            ans = false;
    }

    for (int k = 1; k < n; k++) {
        int count = 0;
        for (int i = 0; i < n-1; i++) {
            if (a[i] <= k) {
                count++;
            }
        }

        if (count > k)
            ans = false;
    }

    cout << (ans ? "YES" : "NO") << endl;

    int path[N], used[N] = {};
    if (ans) {
        sort(a, a+n-1);
        int j = 0;
        path[j++] = a[0];
        used[a[0]] = 1;

        for (int i = 1; i < n-1; i++) {
            if (a[i] > a[i-1]) {
                path[j++] = a[i];
                used[a[i]] = 1;
            } else {
                for (int v = 1; v < a[i]; v++) {
                    if (used[v] == 0) {
                        path[j++] = v;
                        used[v] = 1;
                        break;
                    }
                }
            }
        }

        path[j++] = n;

        for (int i = 0; i < j-1; i++) {
            cout << path[i] << " " << path[i+1] << "\n";
        }
    }
    return 0;
}
