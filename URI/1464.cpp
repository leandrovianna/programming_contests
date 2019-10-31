#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Point;
typedef vector<Point> Polygon;

int cross(Point a, Point b, Point c) {
    return a.first * (b.second - c.second)
            + b.first * (c.second - a.second)
            + c.first * (a.second - b.second);
}

Polygon convexhull(vector<Point> points) {
    const int n = points.size();
    if (n <= 3) {
        return points;
    }

    Polygon hull(2 * n);
    sort(points.begin(), points.end());
    int k = 0;

    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(hull[k-2], hull[k-1], points[i]) < 0) {
            k--;
        }

        hull[k++] = points[i];
    }

    for (int i = n-2, t = k + 1; i >= 0; --i) {
        while (k >= t && cross(hull[k-2], hull[k-1], points[i]) < 0) {
            k--;
        }

        hull[k++] = points[i];
    }

    hull.resize(k);

    return hull;
}

const int N = 2010;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    while (cin >> n, n) {
        vector<Point> points;
        for (int i = 0, x, y; i < n; i++) {
            cin >> x >> y;
            points.push_back({x, y});
        }

        int cnt = 0;
        while (points.size()) {
            auto hull = convexhull(points);
            set<Point> vis;
            // cout << "****\n";
            for (const auto &q : hull) {
                // cout << q.first << " " << q.second << endl;
                vis.insert(q);
            }
            vector<Point> p;
            for (const auto &q : points) {
                if (vis.count(q) == 0) {
                    p.push_back(q);
                }
            }
            cnt++;
            points = p;
        }

        cout << (cnt % 2 == 0 ? "Do not take this onion to the lab!\n"
                            : "Take this onion to the lab!\n");
    }

    return 0;
}
