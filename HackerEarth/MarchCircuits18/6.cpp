//HackerEarth - Problem Name
#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
const double EPS = 1e-9;
const double INF = 1e50;

struct pt;
typedef pair<pt, pt> line;
typedef vector<pt> polygon;

//funcao de comparacao
int cmp(double a, double b = 0.0){
    if(fabs(a-b) < EPS) return 0;
    return a > b ? 1 : -1;
}

//estrutura que representa um ponto
// ou um vetor dependendo da necessidade
struct pt{
    double x, y;

    pt(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    double length() { return sqrt(x*x + y*y); }
    double length2() { return x*x + y*y; }

    pt normalize(){ return (*this)/length(); }

    pt operator - (pt p){ return pt(x - p.x, y - p.y); }
    pt operator + (pt p){ return pt(x + p.x, y + p.y); }
    pt operator * (double k){ return pt(x * k, y * k); }
    pt operator / (double k){ return pt(x / k, y / k); }
    bool operator < (const pt& p) const{
        if(fabs( x - p.x ) >= EPS) return x < p.x;
        return y < p.y;
    }
    bool operator == (const pt p){
        return ( fabs(x - p.x) < EPS && fabs(y - p.y) < EPS );
    }
};

////////////////////
// Funcoes basicas

double dist(pt a, pt b){ return (a - b).length(); }
double dot(pt a, pt b){ return a.x*b.x + a.y*b.y; }
double cross(pt a, pt b){ return a.x*b.y - a.y*b.x; }
double signed_area(pt a, pt b, pt c){ return cross((a-c),(b-c))/2.0; }

/////////////////////
// Orientacao

//Determina o lado que c esta em relacao ao vetor a->b
//1  -> left
//0  -> on
//-1 -> right
int side_sign(pt a, pt b, pt c){ return cmp(signed_area(a, b, c)); }
bool cw(pt a, pt b, pt c){ return cmp(signed_area(a, b, c)) > 0; }
bool ccw(pt a, pt b, pt c){ return cmp(signed_area(a, b, c)) < 0; }
bool colinear(pt a, pt b, pt c){ return !cmp(signed_area(a, b, c)); }

//testa se c esta na caixa limitada por a e b
bool in_box(pt a, pt b, pt c){
    return ( cmp(c.x, min(a.x, b.x)) >= 0 && cmp(c.x, max(a.x, b.x)) <= 0
        &&   cmp(c.y, min(a.y, b.y)) >= 0 && cmp(c.y, max(a.y, b.y)) <= 0 );
}

//verifica se o ponto c se encontra no segmento ab
bool point_and_seg(pt a, pt b, pt c){
    if( !colinear(a, b, c) ) return false;
    return in_box(a, b, c);
}

//gira a em torno da origem por theta radianos
pt rotate(pt a, double theta){ return pt(cos(theta)*a.x - sin(theta)*a.y, sin(theta)*a.x + cos(theta)*a.y); }

//testa se o ponto esta dentro de um poligono (nao necessariamente convexo)
bool inside_poly(pt p, polygon poly){
    poly.push_back(poly[0]);

    for(size_t i = 0; i < poly.size()-1; i++)
        if(point_and_seg(poly[i], poly[i+1], p)) return true; //na borda

    for(size_t i = 0; i < poly.size()-1; i++) poly[i] = poly[i] - p;
    p = pt(0, 0);

    double theta, y;

    while(true){
        theta = (double)rand()/10000.0;

        bool inter = false;
        //evita que um ponto fique no eixo x
        for(size_t i = 0; i < poly.size()-1; i++){
            poly[i] = rotate(poly[i], theta);
            if( !cmp(poly[i].x) ) inter = true;
        }

        if( !inter ){
            poly[poly.size()-1] = poly[0];
            //testa as possiveis intersecoes
            for(size_t i = 0; i < poly.size()-1; i++){
                if( cmp( poly[i].x * poly[i+1].x ) < 0 ){
                    y = poly[i+1].y - poly[i+1].x * (poly[i].y - poly[i+1].y) / (poly[i].x - poly[i+1].x);
                    if( cmp(y) > 0 ) inter = !inter; //se interecao valida
                }
            }
            return inter; //testa a paridade da semi-reta vertical partindo de p
        }
    }
    return true;
}

const int N = 100100;
polygon polys[N];
int n; // number of polygons

int main() {
    ios::sync_with_stdio(false);

    int t, q, x, y, k, op;

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> k;
            for (int j = 0; j < k; j++) {
                cin >> x >> y;
                polys[i].push_back({(double)x, (double)y});
            }
        }

        int qtd = 0;

        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> op;

            if (op == 1) {
                cin >> x >> y;
            } else if (op == 2) {
                cin >> u;
                u--;
            }
        }
    }


    return 0;
}
