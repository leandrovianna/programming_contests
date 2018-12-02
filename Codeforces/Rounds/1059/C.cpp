#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> m;

    if (m == 1)
        cout << "1\n";
    else if (m == 2)
        cout << "1 2\n";
    else if (m == 3)
        cout << "1 1 3\n";
    else {
        n = m;
        bitset<1000100> bit;
        int count = 0;

        for (int i = 1; i <= n; i += 2) {
            cout << "1 ";
            bit[i] = true;
            count++;
        }

        int space = 2;
        while ((int) bit.count() < n) {

            for (int i = space; i <= n; i += 2*space) {
                if (count == n-2) {
                    cout << space << " ";
                    for (int j = n; j >= 1; j--) {
                        if (!bit[j]) {
                            cout << j;
                            break;
                        }
                    }
                    goto fn;
                }

                if (bit[i])
                    continue;

                cout << space << " ";
                bit[i] = true;
                count++;
            }

            space = 2*space;
        }
fn:
        cout << "\n";
    }

    return 0;
}
