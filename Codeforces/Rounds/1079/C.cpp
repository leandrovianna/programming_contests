#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int a[N], b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool valid;

    for (int ini = 1; ini <= 5; ini++) {
        b[0] = ini;
        valid = true;
        for (int i = 0; i < n-1; i++) {
            if (a[i] < a[i+1]) {
                b[i+1] = b[i] + 1;
            } else if (a[i] > a[i+1]) {
                b[i+1] = b[i] - 1;
            } else {
                if (i+2 < n && a[i+1] < a[i+2])
                    b[i+1] = (b[i] == 1 ? 2 : 1);
                else if (i+2 < n && a[i+1] > a[i+2])
                    b[i+1] = (b[i] == 5 ? 4 : 5);
                else
                    b[i+1] = (b[i] > 3 ? b[i] - 1 : b[i] + 1);
            }

            if (b[i+1] < 1 || b[i+1] > 5) {
                valid = false;
                break;
            }
        }

        if (valid) {
            break;
        }
    }

    if (valid) {
        for (int i = 0; i < n; i++) {
            cout << b[i] << " \n"[i == n-1];
        }
    } else {
        cout << "-1\n";
    }

    return 0;
}
