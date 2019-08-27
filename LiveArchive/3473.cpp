// Live Archive - Where are my genes - 3473 - Latin America 2005
#include <bits/stdc++.h>
using namespace std;

const int N = 50010;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, gi = 1, r, q;

    while (cin >> n, n) {
        for (int i = 1; i <= n; i++) {
            a[i] = i;
        }

        cin >> r;
        for (int ri = 0, i, j; ri < r; ri++) {
            cin >> i >> j;
            reverse(a+i, a+j+1);
        }

        cout << "Genome " << gi << "\n";

        cin >> q;
        for (int qi = 0, x; qi < q; qi++) {
            cin >> x;
            for (int i = 1; i <= n; i++) {
                if (a[i] == x) {
                    cout << i << "\n";
                    break;
                }
            }
        }

        gi++;
    }
    return 0;
}
