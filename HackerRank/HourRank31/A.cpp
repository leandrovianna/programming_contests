// Hackerrank - HourRank 31 - Hanging Posters - 1st
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int w[N], l[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h;

    cin >> n >> h;

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, (int) ceil(w[i] - l[i] / 4.0));
    }

    cout << max(0, ans - h) << "\n";
    return 0;
}
