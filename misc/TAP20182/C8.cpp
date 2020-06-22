// TAP 2018/2 - Cheap Trips - C8
// URI - 2905
#include <bits/stdc++.h>
using namespace std;

const int N = 10010, D = 200, M = 10;
double dp[N][D][M];
bool used[N][D][M];
int n;
pair<int, int> trips[N];

double solve(int i, int d, int t) {
    if (i == n)
        return 0;

    if (used[i][d][t])
        return dp[i][d][t];
    used[i][d][t] = true;

    double &ans = dp[i][d][t];

    ans = trips[i].second + 
        solve(i+1, max(0, 120 - trips[i].first), 1); // first trip
    
    if (d > 0 && t < 6) {
        if (t == 1) {
            ans = min(ans, trips[i].second * 0.5 + solve(i+1, max(0, d - trips[i].first), t+1));
        } else if (t > 1) {
            ans = min(ans, trips[i].second * 0.25 + solve(i+1, max(0, d - trips[i].first), t+1));
        }
    }

    return ans;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> trips[i].first >> trips[i].second;
    }

    cout << fixed << setprecision(2);
    cout << solve(0, 0, 0) << endl;
    return 0;
}
