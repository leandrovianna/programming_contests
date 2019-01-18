// Codeforces - Petr and a Combination Lock - 1097B
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 15;
    int deg[N];

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> deg[i];
    }

    bool answer = false;
    for (int mask = 0; mask < (1 << n); mask++) {
        int pointer = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                pointer += deg[i];
            } else {
                pointer -= deg[i];
            }

            pointer = (pointer + 360) % 360;
        }

        if (pointer == 0) {
            answer = true;
            break;
        }
    }

    cout << (answer ? "YES" : "NO") << "\n";

    return 0;
}
