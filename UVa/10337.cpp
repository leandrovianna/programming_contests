// UVA - Flight Planner - 10337
#include <bits/stdc++.h>
using namespace std;

const int N = 1010, A = 10, INF = 1000000000;
int wind[A][N];
int dp[N][A], used[N][A], vis = 0, n;

int f(int pos, int alt) {
    int &ans = dp[pos][alt];

    if (pos == n) {
        return ans = (alt == 0) ? 0 : INF;
    }

    if (used[pos][alt] == vis)
        return ans;

    used[pos][alt] = vis;

    int w = -wind[alt][pos];

    ans = 30 + w + f(pos+1, alt);

    if (alt < 9)
        ans = min(ans, 60 + w + f(pos+1, alt+1));

    if (alt > 0)
        ans = min(ans, 20 + w + f(pos+1, alt-1));

    return ans;
}


int main() {
    int t, x;

    cin >> t;

    while (t--) {
        cin >> x;

        n = x / 100;

        for (int a = 9; a >= 0; a--) {
            for (int i = 0; i < x/100; i++) {
                cin >> wind[a][i];
            }
        }

        vis++;
        cout << f(0, 0) << "\n\n";
    }
    return 0;
}
