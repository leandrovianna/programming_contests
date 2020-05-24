// Codeforces - Minimize the Permutation
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int p[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, n;

    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            vis[i] = false;
        }

        for (int t = 0, x = 1; t < n-1; t++) {
            while (x <= n && p[x-1] == x)
                x++;

            for (int i = 1; i < n; i++) {
                if (p[i] == x) {
                    if (!vis[i] && p[i] < p[i-1]) {
                        vis[i] = true;
                        swap(p[i], p[i-1]);
                    } else {
                        // cant move x, go to next
                        t--; // cancel operation
                        x++;
                    }

                    break;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
