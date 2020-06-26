// Lib - Computational Geometry
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

int main() {
    int n;
    vector<Point<int>> poly;

    cin >> n;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        poly.push_back({x, y});
    }

    return 0;
}
