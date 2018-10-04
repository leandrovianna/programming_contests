// TAP 2018/2 - Interruptores
#include <bits/stdc++.h>
using namespace std;

const int M = 1010, N = 1010;
bool aceso[M];
vector<int> lampadas[N];

int main() {
    int n, m, l;
    
    cin >> n >> m;

    cin >> l;

    for (int i = 0, x; i < l; i++) {
        cin >> x;
        aceso[x] = true;
    }

    for (int i = 0, k; i < n; i++) {
        cin >> k;
        for (int j = 0, x; j < k; j++) {
            cin >> x;
            lampadas[i].push_back(x);
        }
    }

    int ans = 0;
    bool status = false;
    for (int ti = 0; ti < 100; ti++) {
        status = false;
        for (int j = 1; j <= m; j++) {
            status |= aceso[j];
        }

        if (!status) {
            break;
        }

        for (int i = 0; i < n; i++) {
            for (const auto &x : lampadas[i]) {
                aceso[x] = !aceso[x];
            }
            ans++;

            status = false;
            for (int j = 1; j <= m; j++) {
                status |= aceso[j];
            }

            if (!status) {
                break;
            }
        }
    }

    cout << (!status ? ans : -1) << endl;
    return 0;
}
