// UVA - 216 - Getting in Line
#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
const int N = 10;
struct computer {
    int x, y;
} a[N];

int n;
double dp[N][1<<N];
int used[N][1<<N], vis = 1;

int cmp(double x, double y) {
    if (fabs(x - y) < 1e-9)
        return 0;
    else if (x > y)
        return -1;
    else 
        return 1;
}

double dist(int i, int j) {
    return 16.0 + hypot(a[i].x - a[j].x, a[i].y - a[j].y);
}

double solve(int pos, int visited) {
    if (visited == (1 << n)-1)
        return dp[pos][visited] = 0;

    double &ans = dp[pos][visited];

    if (used[pos][visited] == vis)
        return ans;
    used[pos][visited] = vis;

    ans = INF;

    for (int v = 0; v < n; v++) {
        if (v != pos && (visited & (1 << v)) == 0) {
            ans = min(ans, solve(v, visited | (1 << v)) + dist(pos, v));
        }
    }

    return ans;
}

int main() {
    int ti = 1;
    cout << fixed << setprecision(2);

    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y;
        }

        cout << "**********************************************************\n";
        cout << "Network #" << ti << "\n";

        vis++;
        int visited = 1;
        int pos = 0;

        double ans = INF;
        for (int v = 0; v < n; v++) {
            if (ans > solve(v, 1 << v)) {
                ans = solve(v, 1 << v);
                visited = 1 << v;
                pos = v;
            }
        }

        while (visited != (1 << n) - 1) {
            int min_next = pos;

            for (int v = 0; v < n; v++) {
                if (v != pos && cmp(dp[pos][visited], dist(pos, v) + dp[v][visited | (1 << v)]) == 0) {
                    min_next = v;
                }
            }

            assert(pos != min_next);

            cout << "Cable requirement to connect "
                << "(" << a[pos].x << "," << a[pos].y << ")"
                << " to (" << a[min_next].x << "," << a[min_next].y << ")"
                << " is " << dist(pos, min_next) << " feet.\n";

            pos = min_next;
            visited |= (1 << min_next);
        }
        
        cout << "Number of feet of cable required is " << ans << ".\n";
        ti++;
    }
    return 0;
}
