// UVA - The Most Potent Corner - 10264
#include <bits/stdc++.h>
using namespace std;

const int N = 16;
int a[1 << N];
int64_t mark[1 << N];

int main() {
    int n;

    while (cin >> n) {
        for (int i = 0; i < (1 << n); i++) {
            cin >> a[i];
        }

        int64_t ans = 0, l_ans, l_ans2;
        for (int i = 0; i < (1 << n); i++) {
            l_ans = a[i]; // potency of i
            mark[i] = i;

            // mark all neighboors
            for (int j = 0, v; j < n; j++) {
                v = i ^ (1 << j); // flip jth bit
                mark[v] = i;
                l_ans += a[v];
            }

            // for each neighboors, mark its neighboors
            for (int j = 0, v; j < n; j++) {
                l_ans2 = 0; // potency of v
                v = i ^ (1 << j); // flip jth bit

                for (int l = 0, u; l < n; l++) {
                    u = v ^ (1 << l);
                    if (mark[u] != i) {
                        l_ans2 += a[u];
                    }
                }

                // compute the local answer
                ans = max(ans, l_ans + l_ans2);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
