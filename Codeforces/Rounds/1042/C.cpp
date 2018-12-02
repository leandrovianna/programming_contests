// Codeforces - Array Product - 1042C Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int N = 2 * 100 * 1000 + 10;
    int n, neg = 0, f_neg = -1, f_zero = -1, pos = 0;
    int64_t a[N];
    vector<tuple<int, int, int>> op;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        
        if (a[i] < 0) {
            neg++;
            f_neg = i;
        } else if (a[i] == 0) {
            f_zero = i;
            op.push_back({2, i+1, 0});
        } else {
            pos++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (neg & 1 && i == f_neg)
            continue;

        if (a[i] != 0) {
            for (int j = i+1; j < n; j++) {
                if (neg & 1 && j == f_neg)
                    continue;

                if (a[j] != 0) {
                    op.push_back({1, j+1, i+1});
                }
            }
            break;
        }
    }

    for (const auto &p : op) {
        cout << get<0>(p) << " " << get<1>(p);
        if (get<0>(p) == 1)
            cout << " " << get<2>(p);
        cout << "\n";
    }
    return 0;
}
