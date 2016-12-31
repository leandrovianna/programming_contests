#include <iostream>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

bool compara(Point a, Point b) {
    return (a.x <= b.x && a.y >= b.y);
}

int main() {
    const int N = 10;
    int q, n;
    Point p[N];
    string result;
    
    cin >> q;
    for (int qi = 0; qi < q; qi++) {
        cin >> n;
        for (int ni = 0; ni < n; ni++) {
            cin >> p[ni].x >> p[ni].y;
        }
        result = "YES";
        sort(p, p+n, compara);
        Point p0 = p[0];
        Point p1 = p[n-1];
        for (int i = 1; i < n-1; i++) { 
            int x = p[i].x;
            int y = p[i].y;
            
            if (( (x < p0.x || x > p1.x) 
            			|| (y < p1.y || y > p0.y) )
               || (x != p0.x && x != p1.x)
               || (y != p0.y && y != p1.y)) {
                result = "NO";
                break;
            }
        }
        
        cout << result << endl;
    }
    return 0;
}

