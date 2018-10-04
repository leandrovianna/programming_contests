// TAP 2018/2 - Gold Rush - C2
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
bool inner(point p, vector<point> q) {
    double triangles_area = 0, total_area = area(q);

    for (size_t i = 0; i < q.size()-1; i++) {
        vector<point> t = {p, q[i], q[i+1], p};
        triangles_area += area(t);
    }

    return fabs(triangles_area - total_area) < EPS;
}

int main() {
    vector<point> t1, t2;

    for (int i = 0, x, y; i < 3; i++) {
        cin >> x >> y;
        t1.push_back({x, y});
    }
    t1.push_back(t1.front());

    for (int i = 0, x, y; i < 3; i++) {
        cin >> x >> y;
        t2.push_back({x, y});
    }
    t2.push_back(t2.front());

    int ans1 = 0, ans2 = 0;

    for (size_t i = 0; i < t1.size()-1; i++) {
        if (inner(t1[i], t2)) {
            ans1++;
        }
    }

    for (size_t i = 0; i < t2.size()-1; i++) {
        if (inner(t2[i], t1)) {
            ans2++;
        }
    }

    if (ans1 > ans2) {
        cout << "Claim 1 has " << ans1 << " vertices inside Claim 2." << endl;
    } else if (ans2 > ans1) {
        cout << "Claim 2 has " << ans2 << " vertices inside Claim 1." << endl;
    } else {
        cout << "Both claims have equal numbers of intruding points: " << ans1 << endl;
    }

    return 0;
}
