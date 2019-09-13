#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> Point;
 
int cross(Point a, Point b, Point c) {
    return a.first * (b.second - c.second)
            + b.first * (c.second - a.second)
            + c.first * (a.second - b.second);
}
 
const int N = 100100;
pair<int, int> p[N], p2[N], upper[N], lower[N];
int uppersize = 0, lowersize = 0;
 
void ch(int n) {
    sort(p, p+n);
    uppersize = 0;
    lowersize = 0;
 
    for (int i = 0; i < n; i++) {
        while (uppersize >= 2 && cross(upper[uppersize-2], upper[uppersize-1], p[i]) >= 0) {
            uppersize--;
        }
 
        upper[uppersize++] = p[i];
    }
 
    for (int i = 0; i < n; i++) {
        while (lowersize >= 2 && cross(lower[lowersize-2], lower[lowersize-1], p[i]) <= 0) {
            lowersize--;
        }
 
        lower[lowersize++] = p[i];
    }
}
 
double dist(Point a, Point b) {
    return hypot(a.first - b.first, a.second - b.second);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int c;
 
    cin >> c;
 
    for (int i = 0; i < c; i++) {
        cin >> p2[i].first >> p2[i].second;
    }
 
    sort(p2, p2+c);
 
    int n = 0;
 
    p[n++] = p2[0];
 
    for (int i = 1; i < c; i++) {
        if (p2[i] != p2[i-1]) {
            p[n++] = p2[i];
        }
    }
 
    ch(n);
 
    int i = 0, j = lowersize-1;
    double ans = 0;
 
    while (i < uppersize-1 || j > 0) {
        ans = max(ans, dist(upper[i], lower[j]));
 
        if (i == uppersize-1) {
            j--;
        } else if (j == 0) {
            i++;
        } else {
            if ((upper[i+1].second - upper[i].second) * (lower[j].first - lower[j-1].first)
                > (lower[j].second - lower[j-1].second) * (upper[i+1].first - upper[i].first)) {
                i++;
            } else {
                j--;
            }
        }
    }
 
    cout << setprecision(10) << fixed;
    cout << ans << "\n";
 
    return 0;
}
