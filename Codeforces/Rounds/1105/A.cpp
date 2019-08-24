// Codeforces - Salem and Sticks - 1105A - Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 1100;
    int n, a[N];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int answer, cost = 1e9;

    for (int t = 1; t <= 100; t++) {
        int lcost = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] < t)
                lcost += t - 1 - a[i];
            else if (a[i] > t)
                lcost += a[i] - 1 - t;
        }

        if (cost > lcost) {
            cost = lcost;
            answer = t;
        }
    }

    cout << answer << " " << cost << endl;

    return 0;
}
