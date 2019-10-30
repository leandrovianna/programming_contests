#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int c[N], d[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, k;

    cin >> t;
    for (int ti = 1; ti <= t; ti++) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }

        int answer = 0;
        for (int i = 0; i < n; i++) {
            int max1 = c[i], max2 = d[i];
            for (int j = i; j < n; j++) {
                max1 = max(max1, c[j]);
                max2 = max(max2, d[j]);

                if (abs(max1 - max2) <= k) {
                    answer++;
                }
            }
        }

        cout << "Case #" << ti << ": " << answer << "\n";
    }
    return 0;
}
