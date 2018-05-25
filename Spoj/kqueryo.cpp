// Spoj - K-query Online - KQUERYO
#include <bits/stdc++.h>
using namespace std;

bool readChar(char &c) {
	c = getchar_unlocked();
	return c != EOF;
}

inline void writeChar(char c) {
	putchar_unlocked(c);
}

template<typename T>
bool readInt( T &n ) { 
    n = 0; 
    register bool neg = false; 
    register char c = getchar_unlocked(); 
    if( c == EOF) { n = -1; return false; } 
    while (!('0' <= c && c <= '9')) { 
        if( c == '-' ) neg = true; 
        c = getchar_unlocked(); 
    } 
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar_unlocked(); 
    } 
    n = (neg ? (-n) : (n)); 
    return true; 
} 
 
template<typename T>
inline void writeInt(T n){ 
    register int idx = 20; 
    if( n < 0 ) putchar_unlocked('-'); 
    n = abs(n); 
    char out[21]; 
    out[20] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
} 

const int N = 300100;
int a[N];
vector<int> tree[4*N];

vector<int> merge(const vector<int> &a, const vector<int> &b) {
    vector<int> c(a.size() + b.size());
    //merge(a.begin(), a.end(), b.begin(), b.end(), c.begin()); 
    //return c;

    size_t k = 0, h = 0;
    for (auto &x : c) {
        if (k == a.size()) {
            x = b[h];
            h++;
            continue;
        }

        if (h == b.size()) {
            x = a[k];
            k++;
            continue;
        }

        assert(k < a.size() || h < b.size());

        if (a[k] <= b[h]) {
            x = a[k];
            k++;
        } else {
            x = b[h];
            h++;
        }
    }

    return c;
}

void build(int idx, int l, int r) {
    if (l == r) {
        tree[idx].push_back(a[l-1]);
    } else {
        int mid = (l + r) >> 1;
        build(2*idx+1, l, mid);
        build(2*idx+2, mid+1, r);
        tree[idx] = merge(tree[2*idx+1], tree[2*idx+2]);
    }
}

int query(int idx, int l, int r, int x, int y, int k) {
    if (x > r || y < l)
        return 0;

    if (x <= l && r <= y) {
        auto it = upper_bound(tree[idx].begin(), tree[idx].end(), k);
        return tree[idx].end() - it;
    } else {
        int mid = (l + r) >> 1;
        return query(2*idx+1, l, mid, x, y, k)
            + query(2*idx+2, mid+1, r, x, y, k);
    }
}

int main() {
    int n, p, q, r, m;

    readInt(n);
    for (int i = 0; i < n; i++) {
        readInt(a[i]);
    }

    build(0, 1, n);

    readInt(m);
    int l = 0;
    for (int i = 0; i < m; i++) {
        readInt(p);
        readInt(q);
        readInt(r);
        p ^= l;
        q ^= l;
        r ^= l;
        l = query(0, 1, n, p, q, r);
        writeInt(l);
        writeChar('\n');
    }
    return 0;
}
