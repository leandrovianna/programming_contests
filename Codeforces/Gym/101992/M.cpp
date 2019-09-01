// Codeforces - The business man - Egypt Collegiate Programming Contest 2018
#include <bits/stdc++.h>
using namespace std;
 
const int N = 500100;
 
enum {
    SHOPBEGIN, PROD, SHOPEND
};
 
struct Shop {
    int64_t x, q, r;
} shops[N];
struct Product {
    int64_t y, d;
} prods[N];
 
int ft[N];
 
void update(int i, int x) {
    while (i < N) {
        ft[i] += x;
        i += i & (-i);
    }
}
 
int query(int i) {
    int s = 0;
    while (i > 0) {
        s += ft[i];
        i -= i & (-i);
    }
 
    return s;
}
 
int main() {
    ios::sync_with_stdio(false);
 
    fstream fin("business.in");
 
    int t, n, m;
 
    fin >> t;
 
    while (t--) {
        map<int64_t, int> idx;
        vector<int64_t> values;
        vector<pair<int, pair<int, int>>> seq;
        memset(ft, 0, sizeof(ft));
 
        fin >> n >> m;
 
        for (int i = 0; i < n; i++) {
            fin >> shops[i].x 
                >> shops[i].q 
                >> shops[i].r;
 
            int64_t v = shops[i].q - shops[i].x;
            values.push_back(v);
 
            seq.push_back({shops[i].x, {SHOPBEGIN, i}});
            seq.push_back({shops[i].x + shops[i].r, {SHOPEND, i}});
        }
 
        for (int j = 0; j < m; j++) {
            fin >> prods[j].y >> prods[j].d;
 
            values.push_back(prods[j].d - prods[j].y);
            seq.push_back({prods[j].y, {PROD, j}});
        }
 
        int cnt = 1;
        sort(values.begin(), values.end());
        for (const auto &v : values) {
            if (idx.find(v) == idx.end()) {
                idx[v] = cnt++;
            }
        }
 
        sort(seq.begin(), seq.end());
 
        int type, i;
        int64_t v;
        for (const auto &p : seq) {
            type = p.second.first;
            i = p.second.second;
 
            switch (type) {
                case SHOPBEGIN:
                    v = shops[i].q - shops[i].x;
                    update(idx[v], 1);
                    break;
                case SHOPEND:
                    v = shops[i].q - shops[i].x;
                    update(idx[v], -1);
                    break;
                case PROD:
                    v = prods[i].d - prods[i].y;
                    cout << query(cnt) - query(idx[v]-1) << " ";
                    break;
            }
        }
 
        cout << "\n";
    }
    return 0;
}
