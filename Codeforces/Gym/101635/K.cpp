// Codeforces Gym - Blowing Candles - 101635K
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Point {
  T x, y;
  Point() : x(0), y(0) {}
  Point(T x, T y) : x(x), y(y) {}

  Point operator+(Point p) const {
    return {x + p.x, y + p.y};
  }

  Point operator-(Point p) const {
    return {x - p.x, y - p.y};
  }

  Point operator*(T d) const {
    return {x * d, y * d};
  }

  Point operator/(T d) const {
    return {x / d, y / d};
  }

  template<typename S>
  int sgn(S x) {
    return (S(0) < x) - (x < S(0));
  }
};

template<typename T>
bool operator==(Point<T> a, Point<T> b) {
  return a.x == b.x && a.y == b.y;
}

template<typename T>
bool operator!=(Point<T> a, Point<T> b) {
  return !(a == b);
}

template<typename T>
T sq(Point<T> p) {
  return p.x * p.x + p.y * p.y;
}

template<typename T>
double abs(Point<T> p) {
  return sqrt(sq(p));
}

template<typename T>
ostream& operator<<(ostream& os, Point<T> p) {
  return os << "(" << p.x << ", " << p.y << ")";
}

template<typename T>
Point<T> translate(Point<T> v, Point<T> p) {
  return p + v;
}

template<typename T>
Point<T> scale(Point<T> c, double factor, Point<T> p) {
  return c + (p - c) * factor;
}

template<typename T>
Point<T> rotate(Point<T> p, double a) {
  return {p.x * cos(a) - p.y * sin(a),
          p.x * sin(a) + p.y * cos(a)};
}

template<typename T>
Point<T> perp(Point<T> p) {
  return {-p.y, p.x};
}

const int N = 200100;
Point<double> points[N];

Point<double> calc(double angle, const int n) {
  double minx = 1e18, maxx = -1e18;
  double miny = 1e18, maxy = -1e18;
  for (int i = 0; i < n; i++) {
    auto p = rotate(points[i], angle);
    minx = min(minx, p.x);
    maxx = max(maxx, p.x);

    miny = min(miny, p.y);
    maxy = max(maxy, p.y);
  }

  return {maxx - minx, maxy - miny};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, r;

  cin >> n >> r;

  for (int i = 0; i < n; i++) {
    cin >> points[i].x >> points[i].y;
  }

  const double pi = acos(-1), eps = 1e-6;

  double maxvalue = 0, maxangle = 0;
  for (double angle = -pi/2; angle < pi/2; angle += 0.01) {
    double value = calc(angle, n).x;
    if (maxvalue < value) {
      maxangle = angle;
      maxvalue = value;
    }
  }

  double lo = -pi / 2, hi = maxangle, m1, m2;
  while (hi - lo > eps) {
    m1 = lo + (hi-lo) / 3;
    m2 = hi - (hi-lo) / 3;

    auto w1 = calc(m1, n), w2 = calc(m2, n);

    if (w1.x < w2.x) {
      hi = m2;
    } else {
      lo = m1;
    }
  }

  double ans = calc(lo, n).x;

  lo = maxangle;
  hi = pi / 2;
  while (hi - lo > eps) {
    m1 = lo + (hi-lo) / 3;
    m2 = hi - (hi-lo) / 3;

    auto w1 = calc(m1, n), w2 = calc(m2, n);

    if (w1.x < w2.x) {
      hi = m2;
    } else {
      lo = m1;
    }
  }

  ans = min(ans, calc(lo, n).x);

  cout << setprecision(15) << fixed;
  cout << ans << "\n";
  
  return 0;
}
