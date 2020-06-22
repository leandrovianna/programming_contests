// TAP 2018/2 - A6 - Pack the House
#include <bits/stdc++.h>
using namespace std;

const int N = 10100;
int rowqtd[N];

int main() {
    int r, s, g;

    cin >> r >> s >> g;

    int ans = 0; // req. sats.
    for (int gi = 0, q; gi < g; gi++) {
        cin >> q;

        for (int i = 0; i < r; i++) {
            if (rowqtd[i] + q <= s) {
                rowqtd[i] += q;
                ans++;
                break;
            }
        }
    }

    if (g == ans)
        cout << "All groups got tickets." << endl;
    else
        cout << g - ans << " of the " << g 
            << " groups did not get tickets." << endl;

    return 0;
}
