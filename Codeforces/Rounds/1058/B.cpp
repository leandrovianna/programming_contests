// Codeforces - Vasya and Cornfield - 1058B Div2
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
struct point {
    int x, y;
    bool operator==(point &other) {
        return this->x == other.x && this->y == other.y;
    }
};

double area(const vector<point> &q) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)q.size()-1; i++) {
        x1 = q[i].x; 
        x2 = q[i+1].x;
        y1 = q[i].y; 
        y2 = q[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }

    return fabs(result) / 2.0; 
}

// check if point p is inside polygon q
// p can be collinear to edges of polygon q
bool inner2(point p, vector<point> q) {
    double triangles_area = 0, total_area = area(q);

    for (size_t i = 0; i < q.size()-1; i++) {
        vector<point> t = {p, q[i], q[i+1], p};
        triangles_area += area(t);
    }

    return fabs(triangles_area - total_area) < EPS;
}

int main() {
    int n, d, m;

    cin >> n >> d >> m;

    vector<point> poly =
        { {0, d}, {d, 0}, {n, n-d}, {n-d, n}, {0, d} };

    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;

        point p = {x, y};

        if (inner2(p, poly)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
