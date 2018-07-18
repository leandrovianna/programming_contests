#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 10;
struct rect {
    int64_t h, w, ch;
};
rect rec[N];

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> rec[i].w >> rec[i].h;
        rec[i].ch = max(rec[i].w, rec[i].h);
    }

    for (int i = 1; i < n; i++) {
        if (rec[i].ch > rec[i-1].ch) {
            if (rec[i].w <= rec[i-1].ch) {
                rec[i].ch = rec[i].w;
                continue;
            }

            if (rec[i].h <= rec[i-1].ch) {
                rec[i].ch = rec[i].h;
                continue;
            }

            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
