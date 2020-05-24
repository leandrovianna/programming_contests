// Codeforces - Binary String Minimizing
#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    int64_t n, k;
    char ch;

    cin >> q;
    while (q--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> ch;
            a[i] = ch - '0';
        }

        int64_t cnt = 0, moves = 0;
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                cnt++;
            } else {
                if (cnt <= k - moves) {
                    moves += cnt;
                    swap(a[pos], a[i]);
                    pos++;
                } else {
                    swap(a[i-(k-moves)], a[i]);
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
        cout << "\n";
    }
    return 0;
}
