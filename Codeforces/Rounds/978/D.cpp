// Codeforces - Almost Arithmetic Progression - 978D
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int64_t a[N];

int main() {
    ios::sync_with_stdio(false);
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n <= 2) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1 << 25;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            int64_t x = a[0] + di,
                    y = a[1] + dj;
            int cnt = abs(di) + abs(dj);
            bool poss = true;

            for (int i = 2; i < n; i++) {
                int64_t v = x + i * (y - x);
                if (abs(v - a[i]) > 1) {
                    poss = false;
                    break;
                } else if (v != a[i]) {
                    cnt++;
                }
            }

            if (poss) {
                ans = min(ans, cnt);
            }
        }
    }

    cout << (ans == 1 << 25 ? -1 : ans) << endl;

    return 0;
}
