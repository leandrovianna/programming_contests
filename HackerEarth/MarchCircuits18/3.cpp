//HackerEarth - Polygon Partition
#include <bits/stdc++.h>
#include <sys/timeb.h>
using namespace std;

struct timeb ini, fim;
const double EPS = 1e-9;

struct pt;
typedef vector<pt> polygon;

int cmp(double a, double b = 0.0) {
    if (fabs(a-b) < EPS) return 0;
    return a > b ? 1 : -1;
}

//estrutura que representa um ponto
// ou um vetor dependendo da necessidade
struct pt {
    double x, y;
    int pos;
    pt(double x = 0.0, double y = 0.0, int pos = 0) : x(x), y(y), pos(pos) {}

    double length() {
        return sqrt(x*x + y*y);
    }
    double length2() {
        return x*x + y*y;
    }

    pt normalize() {
        return (*this)/length();
    }

    pt operator - (pt p) {
        return pt(x - p.x, y - p.y);
    }
    pt operator + (pt p) {
        return pt(x + p.x, y + p.y);
    }
    pt operator * (double k) {
        return pt(x * k, y * k);
    }
    pt operator / (double k) {
        return pt(x / k, y / k);
    }
    bool operator < (const pt& p) const {
        if (fabs(x - p.x) >= EPS) return x < p.x;
        return y < p.y;
    }
    bool operator == (const pt p) {
        return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
    }
};

////////////////////
// Funcoes basicas

double dist(pt a, pt b) {
    return (a - b).length();
}
double dot(pt a, pt b) {
    return a.x*b.x + a.y*b.y;
}
double cross(pt a, pt b) {
    return a.x*b.y - a.y*b.x;
}
double signed_area(pt a, pt b, pt c) {
    return cross((a-c),(b-c))/2.0;
}

/////////////////////
// Orientacao

//Determina o lado que c esta em relacao ao vetor a->b
//-1  -> right
//0  -> on
//1 -> left
int side_sign(pt a, pt b, pt c) {
    return cmp(signed_area(a, b, c));
}
bool cw(pt a, pt b, pt c) {
    return cmp(signed_area(a, b, c)) > 0;
}
bool ccw(pt a, pt b, pt c) {
    return cmp(signed_area(a, b, c)) < 0;
}
bool colinear(pt a, pt b, pt c) {
    return !cmp(signed_area(a, b, c));
}

double trap(pt& a, pt& b) {
    return 0.5*(b.x - a.x)*(b.y + a.y);
}

double area(polygon& poly) {
    double ret = 0.0;
    for (size_t i = 0; i < poly.size(); i++) {
        ret += trap(poly[i], poly[(i+1)%poly.size()]);
    }
    return fabs(ret);
}
// Convex Hull - funciona pontos colineares
void convex_hull_2(polygon P, polygon& hull) {
    hull.clear();

    // Sort points lexicographically
    sort(P.begin(), P.end());
    P.resize(unique(P.begin(), P.end()) - P.begin());

    // Build lower hull
    for (size_t i = 0; i < P.size(); i ++) {
        while (hull.size() >= 2 && side_sign(hull[hull.size()-2], hull[hull.size()-1], P[i]) <= 0)
            hull.pop_back();
        hull.push_back(P[i]);
    };

    // Build upper hull
    for (int i = P.size()-2, t = hull.size() + 1; i >= 0; i --) {
        while ((int) hull.size() >= t && side_sign(hull[hull.size()-2], hull[hull.size()-1], P[i]) <= 0)
            hull.pop_back();
        hull.push_back(P[i]);
    };
}

int in_hull[2005];
int vis = 1;

void ihuuu(polygon &ori, double &ar, vector < vector < int > > &party) {
    if (ori.size() <= 2) return;
    polygon hull;
    polygon p;
    vector < int > ptt;

    convex_hull_2(ori, hull);
    ar += area(hull);

    for (size_t i = 0; i < hull.size(); i++) {
        in_hull[hull[i].pos] = vis;
        if (i+1 < hull.size()) ptt.push_back(hull[i].pos);
    }

    for (size_t i = 0; i < ori.size(); i++) {
        if (in_hull[ori[i].pos] != vis) {
            p.push_back(ori[i]);
        }
    }

    ori.clear();
    ori = p;
    if (ptt.size()) party.push_back(ptt);
}

void random(int n, polygon &p, polygon &opa) {
    int r = min(rand() % n, n>>1);
    random_shuffle(p.begin(), p.end());

    for (int i = 0; i < r; i++) {
        opa.push_back(p.back());
        p.pop_back();
    }

}

long long rd() {
    return (rand() << 20) + rand();
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < 25; i++)
        srand(rd());

    polygon pontos(n);

    for (int i = 0 ; i < n; i++) {
        cin >> pontos[i].x >> pontos[i].y;
        pontos[i].pos = i;
    }

    vector<vector<int> > ans;
    double resp = 0.;
    double tot = 0.;

    while (tot < 1.60) {
        polygon cp = pontos;
        vector < vector < int > > partitions;
        double ar = 0.;

        while (cp.size() >= 3) {
            ftime(&ini);

            polygon opa;
            random(cp.size(), cp, opa);

            ihuuu(opa, ar, partitions);

            for (size_t i = 0; i < opa.size(); i++) {
                cp.push_back(opa[i]);
            }

            if ((rand() % 8) == 0)
                ihuuu(cp, ar, partitions);

            ftime(&fim);
            double rr = ((double) fim.time + ((double) fim.millitm * 0.001)) - ((double) ini.time + ((double) ini.millitm * 0.001));
            tot += rr;
        }

        vis++;

        if (cp.size()) {
            vector < int > aux;
            for (const auto &it : cp) {
                aux.push_back(it.pos);
            }
            partitions.push_back(aux);
        }

        if (ar > resp) {
            resp = ar;
            ans = partitions;
        }
    }

    cout << ans.size() << "\n";
    for (const auto &v : ans) {
        cout << v.size() << " ";
        for (size_t i = 0; i < v.size(); i++) {
            cout << v[i]+1;
            if (i < v.size()-1)
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
