// Live Archive - 4216 - Pole Position
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int car[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    while (cin >> n, n) {
        memset(car, 0, sizeof(car));

        bool invalid = false;
        for (int i = 1, c, p; i <= n; i++) {
            cin >> c >> p;
            int pos = i + p;
            if (pos <= 0 || pos > n || car[pos] != 0) {
                invalid = true;
            } else {
                car[pos] = c;
            }
        }

        if (invalid) {
            cout << "-1\n";
        } else {
            for (int i = 1; i <= n; i++) {
                cout << car[i];
                if (i == n) cout << "\n";
                else cout << " ";
            }
        }
    }


    return 0;
}
