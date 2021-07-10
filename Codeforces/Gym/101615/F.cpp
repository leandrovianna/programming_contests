// Codeforces Gym - Distinct Distances - 101615F
#include <bits/stdc++.h>
using namespace std;

int64_t lcm(int64_t a, int64_t b) {
  return a * (b / __gcd(a, b));
}

struct Frac {
  int64_t num, den;

  Frac(int64_t num = 0, int64_t den = 1) : num(num), den(den) {}

  Frac reduce() const {
    int64_t g = __gcd(num, den);
    g = abs(g);
    return Frac(num / g, den / g);
  }

  Frac operator+(const Frac& other) const {
    int64_t newden = lcm(den, other.den);
    Frac f(num * (newden / den) + other.num * (newden / other.den), newden);
    return f;
  }

  Frac operator-(const Frac& other) const {
    return *this + Frac(-other.num, other.den);
  }

  Frac operator*(const Frac& other) const {
    return Frac(num * other.num, den * other.den);
  }

  Frac operator/(const Frac& other) const {
    assert(other.num != 0);
    return Frac(num * other.den, den * other.num);
  }
};

ostream& operator<<(ostream& os, const Frac& f) {
  if (f.den == 1)
    os << f.num;
  else
    os << f.num << "/" << f.den;
  return os;
}

bool operator<(const Frac &a, const Frac &b) {
  auto c = a.reduce(), d = b.reduce();

  int64_t den = c.den * d.den;
  c.num *= den / c.den;
  d.num *= den / d.den;

  return c.num < d.num;
}

bool operator==(const Frac &a, const Frac &b) {
  return a.num == b.num && a.den == b.den;
}

bool operator!=(const Frac &a, const Frac &b) {
  return !(a == b);
}

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

template<typename T>
struct Line {
  Point<T> v;
  T c;

  // From direction vector v and offset c
  Line(Point<T> v, T c) : v(v), c(c) {}

  // From equation ax + by = c
  Line(T a, T b, T c) : v({b, -a}), c(c) {}

  // From points P and Q
  Line(Point<T> p, Point<T> q) : v(q-p), c(cross(v,p)) {}

  T side(Point<T> p) {
    return cross(v, p) - c;
  }
  double dist(Point<T> p);
  Line perpThrough(Point<T> p);
  bool cmpProj(Point<T> p, Point<T> q);
  Line translate(Point<T> t);
  void shiftLeft(double dist);
  Point<T> proj(Point<T> p);
  Point<T> refl(Point<T> p);
};

const int N = 50;
Point<Frac> p[N];

int compute_distances(Point<Frac> cand, int n) {
  set<Frac> distances;
  for (int j = 0; j < n; j++) {
    auto deltaX = p[j].x - cand.x;
    auto deltaY = p[j].y - cand.y;
    auto d = deltaX*deltaX + deltaY*deltaY;
    distances.insert(d.reduce());
  }
  return distances.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n; 
  cin >> n;
  
  for (int i = 0, x, y; i < n; i++) {
    cin >> x >> y;
    p[i].x = Frac(x);
    p[i].y = Frac(y);
  }

  const int delta = 25;
  int answer = n;
  for (int i = 0; i < n; i++) {
    for (Frac dx = Frac(-delta); dx < Frac(delta+1); dx = dx + Frac(1)) {
      for (Frac dy = Frac(-delta); dy < Frac(delta+1); dy = dy + Frac(1)) {
        Point q(p[i].x + dx, p[i].y + dy);
        answer = min(answer, compute_distances(q, n));
      }
    }
  }

  cout << answer << "\n";
  return 0;
}
