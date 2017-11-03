#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
int dist[N], n, sub[N];
bool vis[N];

int pre(int i, int p) {
   
    sub[i] = 0;
    
    for (auto &u : g[i]) {
        if (u == p) continue;
        
        if (!vis[u]) {
            vis[u] = true;
            dist[u] = dist[i] + 1;
            pre(u, i);
            sub[i] += sub[u];
        }
    }
    
    sub[i] += 1;
    return dist[i];
}

int main() {
    cin >> n;
    int x, y;
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    dist[1] = 0;
    pre(1, -1);
    
    long double p = 0;
    int64_t acc = 0;
    for (int i = 1; i <= n; i++) {
        acc += dist[i];
    }
 
    for (int i = 1; i <= n; i++) {
        p += (dist[i] / (long double)acc) * (n - sub[i]);
    }
    
    cout << fixed << setprecision(10) << p << endl;
    return 0;
}
