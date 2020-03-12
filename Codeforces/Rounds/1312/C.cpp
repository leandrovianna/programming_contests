// Codeforces - Adding Powers - 1312C
#include <bits/stdc++.h>
using namespace std;

const int E = 70;
int64_t slot[E];
int64_t vs[E];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    int64_t k, x;
    cin >> t;

    while (t--) {
        memset(slot, 0, sizeof(slot));

        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> x;

            int size = 0;
            while (x > 0) {
                vs[size++] = x % k;
                x /= k;
            }

            // cout << "size: " << size << endl;
            for (int j = 0; j < size; j++) {
                slot[j] += vs[j];
            }
        }

        bool ans = true;
        for (int i = 0; i < E; i++) {
            if (slot[i] > 1)
                ans = false;
            // cout << slot[i] << " times " << k << " power to " << i << endl;
        }

        cout << (ans ? "YES": "NO") << "\n";
    }
    return 0;
}
