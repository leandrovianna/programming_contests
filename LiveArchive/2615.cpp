#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;
    bool operator < (Point other) const { // override less than operator
        if (fabs(x - other.x) > EPS)                 // useful for sorting
            return x < other.x;          // first criteria , by x-coordinate
        return y < other.y;
    }          // second criteria, by y-coordinate
    // use EPS (1e-9) when testing equality of two floating points
    bool operator == (Point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
};

ostream& operator << (ostream &out, const Point &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

double dist(Point p1, Point p2) {                // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}           // return double

struct vec {
    double x, y;  // name: `vec' is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};

double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

vec toVec(Point a, Point b) {       // convert 2 Points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(Point p, Point q, Point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

// returns true if point r is on the same line as the line pq
bool collinear(Point p, Point q, Point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

// returns the area, which is half the determinant
double area(const vector<Point> &P) {
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

Point pivot;
bool angleCmp(Point a, Point b) {                 // angle-sorting function
    if (collinear(pivot, a, b))                               // special case
        return dist(pivot, a) < dist(pivot, b);    // check which one is closer
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}   // compare two angles

vector<Point> CH(vector<Point> P) {   
    // the content of P may be reshuffled
    int i, j, n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
        return P;                           // special case, the CH is P itself
    }

    // first, find P0 = Point with lowest Y and if tie: rightmost X
    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;

    Point temp = P[0];
    P[0] = P[P0];
    P[P0] = temp;    // swap P[P0] with P[0]

    // second, sort Points by angle w.r.t. pivot P0
    pivot = P[0];                    // use this global variable as reference
    sort(++P.begin(), P.end(), angleCmp);              // we do not sort P[0]

    // third, the ccw tests
    vector<Point> S;
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

const int N = 110, B = 55;
const double INF = 1e9;
double arr[N], dp[N][B][2];
int used[N][B][2], vis = 1;
int k;

double solve(int i, int b, bool addfirst) {
    if (b < 0) {
        return -INF;
    }

    if (i >= k)
        return b == 0 ? EPS : -INF;

//    if (used[i][b][addfirst] == vis)
//        return dp[i][b][addfirst];
    used[i][b][addfirst] = vis;

    dp[i][b][addfirst] = solve(i+1, b, addfirst);

    if (i != k-1 || !addfirst) {
        dp[i][b][addfirst] = max(dp[i][b][addfirst], 
                arr[i] + solve(i+2, b-1, addfirst || i == 0));
    }

    return dp[i][b][addfirst];
}

int main() {
    int n, b;
    double x, y;

    while (cin >> b >> n, n || b) {
        vector<Point> polygon;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            polygon.push_back({x, y});
        }
        polygon.push_back(polygon.front());

        vector<Point> convex_hull = CH(polygon);

        k = 0;
        double tot = 0;
        for (size_t i = 0; i < convex_hull.size()-1; i++) {
            vector<Point> poly;
            poly.push_back(convex_hull[i]);
            poly.push_back(convex_hull[i+1]);
            poly.push_back(polygon[0]);
            poly.push_back(convex_hull[i]);
            arr[k++] = area(poly);
            tot += arr[k-1];
        }
        arr[k] = 0;

        cout << fixed << setprecision(2);
        cout << tot - solve(0, b, false) << "\n";
        vis++;
    }
    return 0;
}
