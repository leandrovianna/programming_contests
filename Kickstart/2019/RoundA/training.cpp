#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int64_t s[N]; // skill level

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, p;

    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cin >> n >> p;

        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        sort(s, s+n);

        int64_t diff = 0, answer = 1e10;

        for (int i = 0; i < p; i++) {
            diff += s[p-1] - s[i];
        }

        answer = diff;

        for (int i = 1; i <= n-p; i++) {
            diff -= s[i+p-2] - s[i-1];
            diff += (p-1) * (s[i+p-1] - s[i+p-2]);

            answer = min(answer, diff);
        }

        cout << "Case #" << ti << ": " << answer << "\n";
    }

    return 0;
}
