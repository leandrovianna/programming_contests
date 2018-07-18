// Lib - Computational Geometry
#include <bits/stdc++.h>
using namespace std;

const double PI = 3.14159265358979323846;
const double EPS = 1e-9;

struct point {
    int x, y;
    bool operator==(point &other) {
        return this->x == other.x && this->y == other.y;
    }
};

struct vec { 
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {} 
};

// Note about polygons: vector<point> with
// the first and last positions equals (same point)
// is a polygon

vec to_vec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y); 
}

double dot(vec a, vec b) { 
    return (a.x * b.x + a.y * b.y); 
}

double norm_sq(vec v) { 
    return v.x * v.x + v.y * v.y; 
}

double cross(vec a, vec b) { 
    return a.x * b.y - a.y * b.x; 
}

bool collinear(point p, point q, point r) {
    return fabs(cross(to_vec(p, q), to_vec(p, r))) < EPS; 
}

double angle(point a, point o, point b) { 
    vec oa = to_vec(o, a), ob = to_vec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); 
}

bool ccw(point p, point q, point r) {
    return cross(to_vec(p, q), to_vec(p, r)) > 0; 
}

// ccw with support to collinear points
bool coccw(point p, point q, point r) {
    if (collinear(p, q, r))
        return true;

    return cross(to_vec(p, q), to_vec(p, r)) > 0; 
}

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y); 
}

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

// check if point p is inside polygon p
// restrictions: p can not be collinear 
// with points of q
bool inner(point p, vector<point> q) {
    if (q.size() == 0) return false;

    double sum = 0;
    for (size_t i = 0; i < q.size()-1; i++) {
        if (ccw(p, q[i], q[i+1])) {
            sum += angle(q[i], p, q[i+1]);
        } else {
            sum -= angle(q[i], p, q[i+1]);
        }
    }

    // fabs(sum) == 2 * PI
    return fabs(fabs(sum) - 2 * PI) < EPS;
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
    int n;
    vector<point> poly;

    cin >> n;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        poly.push_back({x, y});
    }

    cout << "area: " << area(poly) << endl;
    return 0;
}
