#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))

double DEG_to_RAD(double d) {
    return d * PI / 180.0;
}

double RAD_to_DEG(double r) {
    return r * 180.0 / PI;
}

// struct point_i { int x, y; };    // basic raw form, minimalist mode
struct point_i {
    int x, y;     // whenever possible, work with point_i
    point_i() {
        x = y = 0;    // default constructor
    }
    point_i(int _x, int _y) : x(_x), y(_y) {}
};         // user-defined

struct point {
    double x, y;   // only used if more precision is needed
    point() {
        x = y = 0.0;    // default constructor
    }
    point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
    bool operator < (point other) const { // override less than operator
        if (fabs(x - other.x) > EPS)                 // useful for sorting
            return x < other.x;          // first criteria , by x-coordinate
        return y < other.y;
    }          // second criteria, by y-coordinate
    // use EPS (1e-9) when testing equality of two floating points
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
};

double dist(point p1, point p2) {                // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}           // return double

// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) {
    double rad = DEG_to_RAD(theta);    // multiply theta with PI / 180.0
    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}

struct line {
    double a, b, c;
};          // a way to represent a line

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;           // default values
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

// not needed since we will use the more robust form: ax + by + c = 0 (see above)
struct line2 {
    double m, c;
};      // another way to represent a line

int pointsToLine2(point p1, point p2, line2 &l) {
    if (abs(p1.x - p2.x) < EPS) {          // special case: vertical line
        l.m = INF;                    // l contains m = INF and c = x_value
        l.c = p1.x;                  // to denote vertical line x = x_value
        return 0;   // we need this return variable to differentiate result
    }
    else {
        l.m = (double)(p1.y - p2.y) / (p1.x - p2.x);
        l.c = p1.y - l.m * p1.x;
        return 1;     // l contains m and c of the line equation y = mx + c
    }
}

bool areParallel(line l1, line l2) {       // check coefficients a & b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2) {           // also check coefficient c
    return areParallel(l1,l2) && (fabs(l1.c - l2.c) < EPS);
}

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;            // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);
    return true;
}

struct vec {
    double x, y;  // name: `vec' is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {       // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s) {        // nonnegative s = [<1 .. 1 .. >1]
    return vec(v.x * s, v.y * s);
}               // shorter.same.longer

point translate(point p, vec v) {        // translate p according to v
    return point(p.x + v.x, p.y + v.y);
}

// convert point and gradient/slope to line
void pointSlopeToLine(point p, double m, line &l) {
    l.a = -m;                                               // always -m
    l.b = 1;                                                 // always 1
    l.c = -((l.a * p.x) + (l.b * p.y));
}                // compute this

void closestPoint(line l, point p, point &ans) {
    line perpendicular;         // perpendicular to l and pass through p
    if (fabs(l.b) < EPS) {              // special case 1: vertical line
        ans.x = -(l.c);
        ans.y = p.y;
        return;
    }

    if (fabs(l.a) < EPS) {            // special case 2: horizontal line
        ans.x = p.x;
        ans.y = -(l.c);
        return;
    }

    pointSlopeToLine(p, 1 / l.a, perpendicular);          // normal line
    // intersect line l with this perpendicular line
    // the intersection point is the closest point
    areIntersect(l, perpendicular, ans);
}

// returns the reflection of point on a line
void reflectionPoint(line l, point p, point &ans) {
    point b;
    closestPoint(l, p, b);                     // similar to distToLine
    vec v = toVec(p, b);                             // create a vector
    ans = translate(translate(p, v), v);
}         // translate p twice

double dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
    return v.x * v.x + v.y * v.y;
}

// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));                  // translate a to c
    return dist(p, c);
}           // Euclidean distance between p and c

// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) {
        c = point(a.x, a.y);                   // closer to a
        return dist(p, a);
    }         // Euclidean distance between p and a
    if (u > 1.0) {
        c = point(b.x, b.y);                   // closer to b
        return dist(p, b);
    }         // Euclidean distance between p and b
    return distToLine(p, a, b, c);
}          // run distToLine as above

double angle(point a, point o, point b) {  // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

//// another variant
//int area2(point p, point q, point r) { // returns 'twice' the area of this triangle A-B-c
//  return p.x * q.y - p.y * q.x +
//         q.x * r.y - q.y * r.x +
//         r.x * p.y - r.y * p.x;
//}

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

// circles

int insideCircle(point_i p, point_i c, int r) { // all integer version
    int dx = p.x - c.x, dy = p.y - c.y;
    int Euc = dx * dx + dy * dy, rSq = r * r;             // all integer
    return Euc < rSq ? 0 : Euc == rSq ? 1 : 2;
} //inside/border/outside

bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
} // to get the other center, reverse p1 and p2

double perimeter(double ab, double bc, double ca) {
    return ab + bc + ca;
}

double perimeter(point a, point b, point c) {
    return dist(a, b) + dist(b, c) + dist(c, a);
}

double area(double ab, double bc, double ca) {
    // Heron's formula, split sqrt(a * b) into sqrt(a) * sqrt(b); in implementation
    double s = 0.5 * perimeter(ab, bc, ca);
    return sqrt(s) * sqrt(s - ab) * sqrt(s - bc) * sqrt(s - ca);
}

double area(point a, point b, point c) {
    return area(dist(a, b), dist(b, c), dist(c, a));
}

double rInCircle(double ab, double bc, double ca) {
    return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca));
}

double rInCircle(point a, point b, point c) {
    return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}

// assumption: the required points/lines functions have been written
// returns 1 if there is an inCircle center, returns 0 otherwise
// if this function returns 1, ctr will be the inCircle center
// and r is the same as rInCircle
int inCircle(point p1, point p2, point p3, point &ctr, double &r) {
    r = rInCircle(p1, p2, p3);
    if (fabs(r) < EPS) return 0;                   // no inCircle center

    line l1, l2;                    // compute these two angle bisectors
    double ratio = dist(p1, p2) / dist(p1, p3);
    point p = translate(p2, scale(toVec(p2, p3), ratio / (1 + ratio)));
    pointsToLine(p1, p, l1);

    ratio = dist(p2, p1) / dist(p2, p3);
    p = translate(p1, scale(toVec(p1, p3), ratio / (1 + ratio)));
    pointsToLine(p2, p, l2);

    areIntersect(l1, l2, ctr);           // get their intersection point
    return 1;
}

double rCircumCircle(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * area(ab, bc, ca));
}

double rCircumCircle(point a, point b, point c) {
    return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}

// assumption: the required points/lines functions have been written
// returns 1 if there is a circumCenter center, returns 0 otherwise
// if this function returns 1, ctr will be the circumCircle center
// and r is the same as rCircumCircle
int circumCircle(point p1, point p2, point p3, point &ctr, double &r) {
    double a = p2.x - p1.x, b = p2.y - p1.y;
    double c = p3.x - p1.x, d = p3.y - p1.y;
    double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
    double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
    double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));
    if (fabs(g) < EPS) return 0;

    ctr.x = (d*e - b*f) / g;
    ctr.y = (a*f - c*e) / g;
    r = dist(p1, ctr);  // r = distance from center to 1 of the 3 points
    return 1;
}

// returns true if point d is inside the circumCircle defined by a,b,c
int inCircumCircle(point a, point b, point c, point d) {
return (a.x - d.x) * (b.y - d.y) * ((c.x - d.x) * (c.x - d.x) + 
        (c.y - d.y) * (c.y - d.y)) +
(a.y - d.y) * ((b.x - d.x) * (b.x - d.x) + (b.y - d.y) * (b.y - d.y)) 
        * (c.x - d.x) +
((a.x - d.x) * (a.x - d.x) + (a.y - d.y) * (a.y - d.y)) * (b.x - d.x) 
        * (c.y - d.y) -
((a.x - d.x) * (a.x - d.x) + (a.y - d.y) * (a.y - d.y)) * (b.y - d.y) 
        * (c.x - d.x) -
(a.y - d.y) * (b.x - d.x) * ((c.x - d.x) * (c.x - d.x) + (c.y - d.y) 
        * (c.y - d.y)) -
(a.x - d.x) * ((b.x - d.x) * (b.x - d.x) + (b.y - d.y) * (b.y - d.y)) 
        * (c.y - d.y) > 0 ? 1 : 0;
}

bool canFormTriangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// returns the perimeter, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double perimeter(const vector<point> &P) {
    double result = 0.0;
    for (int i = 0; i < (int)P.size()-1; i++)  // remember that P[0] = P[n-1]
        result += dist(P[i], P[i+1]);
    return result;
}

// returns the area, which is half the determinant
double area(const vector<point> &P) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size()-1; i++) {
        x1 = P[i].x;
        x2 = P[i+1].x;
        y1 = P[i].y;
        y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0;
}

// returns true if we always make the same turn while examining
// all the edges of the polygon one by one
bool isConvex(const vector<point> &P) {
    int sz = (int)P.size();
    if (sz <= 3) return false;   // a point/sz=2 or a line/sz=3 is not convex
    bool isLeft = ccw(P[0], P[1], P[2]);               // remember one result
    for (int i = 1; i < sz-1; i++)            // then compare with the others
        if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
            return false;            // different sign -> this polygon is concave
    return true;
}                                  // this polygon is convex

// returns true if point p is in either convex/concave polygon P
bool inPolygon(point pt, const vector<point> &P) {
    if ((int)P.size() == 0) return false;
    double sum = 0;    // assume the first vertex is equal to the last vertex
    for (int i = 0; i < (int)P.size()-1; i++) {
        if (ccw(pt, P[i], P[i+1]))
            sum += angle(P[i], pt, P[i+1]);                   // left turn/ccw
        else sum -= angle(P[i], pt, P[i+1]);
    }                 // right turn/cw
    return fabs(fabs(sum) - 2*PI) < EPS;
}

// line segment p-q intersect with line A-B.
point lineIntersectSeg(point p, point q, point A, point B) {
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v));
}

// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
    vector<point> P;
    for (int i = 0; i < (int)Q.size(); i++) {
        double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
        if (i != (int)Q.size()-1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
        if (left1 > -EPS) P.push_back(Q[i]);       // Q[i] is on the left of ab
        if (left1 * left2 < -EPS)        // edge (Q[i], Q[i+1]) crosses line ab
            P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
    }
    if (!P.empty() && !(P.back() == P.front()))
        P.push_back(P.front());        // make P's first point = P's last point
    return P;
}

point pivot;
bool angleCmp(point a, point b) {                 // angle-sorting function
    if (collinear(pivot, a, b))                               // special case
        return dist(pivot, a) < dist(pivot, b);    // check which one is closer
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}   // compare two angles

vector<point> CH(vector<point> P) {   // the content of P may be reshuffled
    int i, j, n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
        return P;                           // special case, the CH is P itself
    }

    // first, find P0 = point with lowest Y and if tie: rightmost X
    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;

    point temp = P[0];
    P[0] = P[P0];
    P[P0] = temp;    // swap P[P0] with P[0]

    // second, sort points by angle w.r.t. pivot P0
    pivot = P[0];                    // use this global variable as reference
    sort(++P.begin(), P.end(), angleCmp);              // we do not sort P[0]

    // third, the ccw tests
    vector<point> S;
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]);   // initial S
    i = 2;                                         // then, we check the rest
    while (i < n) {           // note: N must be >= 3 for this method to work
        j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);  // left turn, accept
        else S.pop_back();
    }   // or pop the top of S until we have a left turn
    return S;
}                                          // return the result

int main() {
    return 0;
}
